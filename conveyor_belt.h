//
// Created by Parth Parakh on 18/02/21.
//

#ifndef CONVEYOR_BELT_CONVEYOR_BELT_H
#define CONVEYOR_BELT_CONVEYOR_BELT_H

#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include"shuffling.h"

// could have made the class as a singleton class since we can only have one conveyor belt in this design.
// single responsibility principle violated ?
class CBelt
{
private:
    std::unordered_map<int,std::string> node;
    std::unordered_set<std::string> finish;
    std::unordered_set<std::string> unused;
    int length_belt;
    int length_random;
    int count_products;
    int count_unused;

    // dependency injection
    // using smart pointers ?
    shuffling *sh;
public:
    std::vector<std::string> belt;
    CBelt(int lb,int lr);
    void init();
    void count_state();
    void get_final() const;
};

#endif //CONVEYOR_BELT_CONVEYOR_BELT_H
