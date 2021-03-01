//
// Created by Parth Parakh on 18/02/21.
//

#include "shuffling.h"
#include<random>
#include<algorithm>
#include<iostream>
#include<chrono>

shuffling::shuffling(int len) : length(len)
{
    for(int i=1;i<=length;i++)
    {
        random.push_back(i);
    }
};

int shuffling::get_number()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (random.begin(), random.end(), std::default_random_engine(seed));
    //for (int& x: random) std::cout << ' ' << x ;
    //std::cout<<std::endl;
    return random[0];
}

