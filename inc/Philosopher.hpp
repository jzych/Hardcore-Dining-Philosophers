#pragma once
#include "Book.hpp"
#include <mutex>
class Waiter; // forward reference

class Philosopher {
    Log& log_;
    Book& book_;
    Waiter& waiter_;
    bool alive = true;

    void eat();
    void think();
    void sleep();
public:
    Philosopher(Log& l, Book& b, Waiter& w);
    ~Philosopher();

    void dine();
};
