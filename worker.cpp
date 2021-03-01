//
// Created by Parth Parakh on 18/02/21.
//

#include "worker.h"

Worker::Worker(int&& init_value)
{
    state = init_value;
}

int Worker::get_state() const
{
    return state;
}

void Worker::set_state(int &&new_value)
{
    state = new_value;
}

