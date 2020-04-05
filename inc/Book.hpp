#pragma once
#include <string>
#include <chrono>
#include <vector>
#include <shared_mutex>
#include <random>
#include <functional>
#include "Log.hpp"

struct Thought {
    std::string philosopher;
    std::string answer;
    int result;
    std::chrono::milliseconds period;
    bool chosen = false;
};

class Book {
    Log& log_;
    std::vector<Thought> records_;
    mutable std::shared_mutex m_;
    std::mt19937 seed{ std::random_device{}() };

public:
    Book(Log& log);
    ~Book();

    void add_record(Thought t);     // Adds Thought to Book
    Thought read_random_record();   // Returns random Thought from Book
                                    // Returns Thought with highest score from
                                    //  provided function for given Philosopher
    Thought* get_record_with_highest_score(std::string name,
                std::function<int(int, std::chrono::milliseconds)> scoreFunc);
};
