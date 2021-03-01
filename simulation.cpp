//
// Created by Parth Parakh on 18/02/21.
//

#include "simulation.h"

/*EXPLANATION
 * this is the engine of our system.
 * we have actions which is a 2D array of 100*3. This is basically used to differentiate between left workers (top workers)
 * and right workers (bottom workers). The first chance is given to left worker, if the left worker succeeds in taking the element
 * from the conveyor belt then action is marked as true and right worker wont be able to touch the cb then. The same is implemented for
 * all the three workers on either side for all slots ( hence 100*3 ).
 * Another way could have been to make the entire operation atomic for each worker and have three parallel thread running
 * however it would have made the entire function quite complicated.
 *
 *similarly worker is being initialised and added to a vector of workers. we have two of these workers on either side of the cb.
 *
 * we can also use factory design to create workers and use wrapper class to get clones of the worker which can then be used by the simulation class
 * */
simulation::simulation(int lb,  int nw) : length_belt(lb), number_of_workers(nw)
{
    action.resize(number_of_workers);
    for (int i=0;i< number_of_workers;i++)
    {
        action[i].resize(length_belt);
    }
    //std::vector<Worker> worker_L { static_cast<size_t>(number_of_workers),Worker(0) };
    //std::vector<Worker> worker_R { static_cast<size_t>(number_of_workers),Worker(0) };
    for(int i=0;i<number_of_workers;i++)
    {
        Worker worker_l(0);
        Worker worker_r(0);
        worker_L.push_back(worker_l);
        worker_R.push_back(worker_r);
    }
}

//functor

/*EXPLANATION
 * action has already being explained above, side is used to decide if we have to choose left worker or right.
 * flag is set to true when we have both the components ( a & (b||c) ). counter is used to count till 4 which is the time
 * it takes to create p or q from the time we have all the initial components. once the counter reaches 4, we take the
 * product and replace it with the component from the belt (swap).
 * Different states we are considering :
 * if state is 0 ( empty hands ), we take any component.
 * if state is 1 ( A in hand ), we find and take b or c.
 * if state is 2/3 ( B/C in hand), we find and take a.
 * once we have a and b/c, we change the state to 4/5 (p/q) and wait for timer to go off.
 * once timer goes off ( 4 counts ) we replace our product with any component thats found.
 * */
void simulation::operator()(int i,int j,int && side, CBelt &cb)
{
    if(action[j][i] ==1 ) return;
    Worker *w;
    if(side==0)
    {
        w = &worker_L[j];
    }
    else
    {
        w = &worker_R[j];
    }
    if( w->flag==1)
    {
        w->counter++;
        //std::cout<<"counter : "<<w->counter<<std::endl;
        //std::cout<<"state in counter loop : "<<w->get_state()<<std::endl;
        //std::cout<<"belt in counter loop : "<<cb.belt[i]<<std::endl;
    }
    if(w->get_state()==0 && cb.belt[i]!="nullptr")
    {
        //std::cout<<"its coming in loop 1"<<std::endl;
        if(cb.belt[i]=="A") w->set_state(1);
        else if( cb.belt[i]=="B") w->set_state(2);
        else if( cb.belt[i]=="C") w->set_state(3);
        //std::cout<<w->get_state()<<std::endl;

        //since we have taken the component,changing the state to null to prevent other workers from taking the same component
        cb.belt[i]="nullptr";
        // if left hand side worker has done an operation then right hand side worker cant do
        action[j][i] = 1;
    }
    if(w->get_state()==1 && (cb.belt[i]=="B" || cb.belt[i]=="C") )
    {
        //std::cout<<"its coming in loop 2"<<std::endl;
        w->flag = 1;
        w->counter++;
        if(cb.belt[i]=="B")
        {
            w->set_state(4);
        }
        else
        {
            w->set_state(5);
        }
        //std::cout<<w->get_state()<<std::endl;
        cb.belt[i]="nullptr";
        action[j][i] = 1;
    }
    if( (w->get_state()==2 || w->get_state()==3 ) && cb.belt[i]=="A" )
    {
        //std::cout<<"its coming in loop 3"<<std::endl;
        w->flag = 1;
        w->counter++;
        if(w->get_state()==2)
        {
            w->set_state(4);
        }
        else
        {
            w->set_state(5);
        }
        //std::cout<<w->get_state()<<std::endl;
        cb.belt[i]="nullptr";
        action[j][i] = 1;
    }
    if( (w->get_state()==4 || w->get_state()==5 ) && w->counter>3)
    {
        //std::cout<<"its coming in loop 4"<<std::endl;
        w->flag = 0;
        w->counter=0;
        if(cb.belt[i]=="A") w->set_state(1);
        else if( cb.belt[i]=="B") w->set_state(2);
        else if( cb.belt[i]=="C") w->set_state(3);
        if( w->get_state()==4 ) cb.belt[i]="P";
        else cb.belt[i]="Q";
        //std::cout<<"update belt : "<<cb.belt[i]<<std::endl;
    }
}