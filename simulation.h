//
// Created by Parth Parakh on 18/02/21.
//

#ifndef CONVEYOR_BELT_SIMULATION_H
#define CONVEYOR_BELT_SIMULATION_H

#include<iostream>
#include<vector>
#include"worker.h"
#include"conveyor_belt.h"

// can be made base class and have a child class implementation to implement this particular simulation.
// adds more flexibility if we want different simulations. Also we are passing a reference to CBelt here in the functor, if we wanted to change this
// we could add pass a base class pointer/ref for CBelt as well and have different implementations for it. Same goes for the workers.
// Bottom Line is if this particular combination of workers/cbelt is to be changed we could incorporate a bridge pattern between
// simulation and workers or/and simulation and cbelt and play around with as many different combinations as we want.
class simulation
{
private:
    int length_belt;
    int number_of_workers;
    std::vector<std::vector<int>> action;
    std::vector<Worker> worker_L;
    std::vector<Worker> worker_R;
public:
    simulation( int lb,  int nw);
    void operator()(int i,int j, int&& side, CBelt &cb);
};
#endif //CONVEYOR_BELT_SIMULATION_H
