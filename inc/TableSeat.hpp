#pragma once
#include "Philosopher.hpp"
#include "Fork.hpp"

struct TableSeat {
    Philosopher& philo;
    Fork fork;
    int starvation = 0;
};
