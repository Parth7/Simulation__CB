//
// Created by Parth Parakh on 18/02/21.
//

#ifndef CONVEYOR_BELT_SHUFFLING_H
#define CONVEYOR_BELT_SHUFFLING_H

#include<vector>

// could have made this a template instead of specifying the type(int)
// could have used functors instead of get_number
// maybe not the most efficient way of implementing RNG
// could have made this a base/interface class and have different implementations in the child classes
class shuffling
{
private:
    int length;
    std::vector<int> random;
public:
    explicit shuffling(int len);
    int get_number();
};


#endif //CONVEYOR_BELT_SHUFFLING_H
