#pragma once
#include <vector>
#include "TableSeat.hpp"
#include "Log.hpp"

class Waiter
{
    Log& log_;
    std::vector<TableSeat> table_;

    bool check_neighbour_stavation(std::string name);
public:
    explicit Waiter(Log& log);
    ~Waiter();

    void register_philosopher(Philosopher& p);
    bool deliver_forks(const Philosopher& p, Fork& fork_left, Fork& fork_right);
};
