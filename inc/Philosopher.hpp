#pragma once
#include "Book.hpp"
#include "Waiter.hpp"
#include <mutex>

class Philosopher {
    Book& book_;
    Waiter waiter_;
    std::mutex& leftFork_;
    std::mutex& rightFork_;

public:
    Philosopher(Book& book, Waiter& waiter, std::mutex& leftFork, std::mutex& rightFork_);
};
