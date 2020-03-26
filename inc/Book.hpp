#pragma once
#include <string>
#include <chrono>
#include <vector>
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

public:
    Book(Log& log);
    ~Book();

    void addRecord(Thought t);      // Adds Thought to Book
    Thought readRandomRecord();     // Returns random Thought from Book
                                    // Returns Thought with highest score from
                                    //  provided function for given Philosopher
    Thought getRecordWithHighestScore(std::string name,
                                      int (*scoreFunc)(int, std::chrono::milliseconds));
};
