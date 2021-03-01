//
// Created by Parth Parakh on 18/02/21.
//

#include "conveyor_belt.h"
#include"shuffling.h"
#include <iostream>

CBelt::CBelt(int lb, int lr) : length_belt(lb), length_random(lr) 
{
    // instead of directly using a pointer to random number generation class we could have used a wrapper class
    // that creates a copy of rng class object that is specific for this conveyor belt.
    // if there was a other class using the same object and deletes the object after use, we will be left with a dangling pointer.
    sh = new shuffling(length_random);

    // can use enums instead of magic numbers here
    // not a scalable solution but decided to use this hack of repeating A twice to get the 2/5 probability of selecting it.
    // rest of the components have a probability of 1/5 of being selected.
    node[1] = "nullptr";
    node[2] = "A";
    node[3] = "B";
    node[4] = "A";
    node[5] = "C";

    //specifying the different types of finish products we can have.
    // we could also take a list of finish products as an argument from the user while initializing and run a for loop
    finish.insert("P");
    finish.insert("Q");

    //specifying the different types of components we have.
    // same as above, could have taken as an argument.
    unused.insert("A");
    unused.insert("B");
    unused.insert("C");

    // count the actual number of products created
    // count the actual number of unused components left on the belt.
    count_products = 0;
    count_unused = 0;
};
void CBelt::init()
{
    for(int i=0;i<length_belt;i++)
    {
        int random = sh->get_number();
        belt.push_back(node[random]);
        //std::cout<<"initial belt state : "<<belt[i]<<std::endl;
    }
}

void CBelt::count_state()
{
    for(int i=0;i<length_belt;i++)
    {
        //std::cout<<"belt state : "<<belt[i]<<std::endl;
        if(finish.find(belt[i])!=finish.end())
        {
            count_products++;
        }
        else if(unused.find(belt[i])!=unused.end())
        {
            count_unused++;
        }
    }
}

void CBelt::get_final() const
{
    std::cout<<"No. of final products created : "<<count_products<< std::endl;
    std::cout<<"No of unused components left on the conveyor belt : " << count_unused << std::endl;
}


