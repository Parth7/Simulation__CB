//
// Created by Parth Parakh on 18/02/21.
//

#ifndef CONVEYOR_BELT_WORKER_H
#define CONVEYOR_BELT_WORKER_H

#include<vector>

/*
 * this is the simple class here. it keeps a tab on the state of each worker and counter and flag. counter is used to
 * store counts till 4 before the product can be kept on the belt. flag is to indicate if we have all the components or not.
 * could have used better variable names than the generic counter and flag.
 */

class Worker
{
private:
    /*
        0 -> empty hand
        1 -> A in hand
        2 -> B in hand
        3 -> C in hand
        4 -> P in hand
        5 -> Q in hand
     */
    int state;
public:
    int flag=0;
    int counter=0;
    explicit Worker(int&& init_value);
    [[nodiscard]] int get_state() const;
    void set_state(int &&new_value);
};

#endif //CONVEYOR_BELT_WORKER_H
