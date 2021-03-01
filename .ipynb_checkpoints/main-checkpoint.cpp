//#include <iostream>
#include"simulation.h"
#include"conveyor_belt.h"

int main()
{
    int random_numbers = 5;
    int length_belt = 100;
    int number_of_workers = 3;
    CBelt c_belt(length_belt,random_numbers);
    c_belt.init();
    simulation Simulation(length_belt,number_of_workers);
    for(int i=0;i<length_belt;i++)
    {
        for(int j=0;j<number_of_workers;j++)
        {
            Simulation(i,j,0,c_belt);
            Simulation(i,j,1,c_belt);
        }
    }
    c_belt.count_state();
    c_belt.get_final();
    return 0;
}
