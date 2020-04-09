#include "Philosopher.hpp"

Philosopher::Philosopher(Log& l, Book& b, Waiter& w) : log_(l),
                                                       book_(b),
                                                       waiter_(w) {
}
