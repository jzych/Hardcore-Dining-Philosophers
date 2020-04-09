#pragma once
#include <mutex>
#include "Philosopher.hpp"
#include "Fork.hpp"

struct TableSeat {
    Philosopher& philo;
    std::mutex fork;
    int starvation = 0;
};
