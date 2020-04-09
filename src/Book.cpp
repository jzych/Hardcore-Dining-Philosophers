#include "Book.hpp"
#include <algorithm>

Book::Book(Log& log) : log_(log) {
    log_.logDebug("Book is opened");
}

Book::~Book() {
    log_.logDebug("Book is closed");
}

void Book::add_record(Thought t) {
    std::unique_lock lock(m_);
    records_.push_back(t);

    log_.logInfo(t.philosopher + " has witten new thought in Book");
    log_.logDebug("answer: " + t.answer + ", result: " + std::to_string(t.result)
                  + ", period: " + std::to_string(t.period.count()));
}

Thought Book::read_random_record() {
    std::shared_lock lock(m_);

    if (records_.empty()) {
        Thought tmp;
        tmp.philosopher = "";
        tmp.answer = "";
        tmp.result = 0;
        tmp.period = std::chrono::milliseconds{0};

        return tmp;
    }

    std::uniform_int_distribution<> rand{0, static_cast<int>(records_.size())};
    return records_[rand(seed)];
}

Thought* Book::get_record_with_highest_score(std::string name,
                std::function<int(int, std::chrono::milliseconds)> scoreFunc) {
    int score = 0;
    Thought* bestThought = nullptr;

    if (records_.empty()){
        log_.logError("Cannot find best thought in empty Book!");
        return bestThought;
    }

    auto func = [&](Thought& t) {
        if(t.philosopher == name) {
            int tmpScore = scoreFunc(t.result, t.period);

            if(tmpScore > score) {
                score = tmpScore;
                bestThought = &t;
            }
        }
    };

    for_each(records_.begin(), records_.end(), func);
    log_.logDebug("Found best score: " + std::to_string(
                  scoreFunc(bestThought->result, bestThought->period))
                  + " in " + bestThought->philosopher + "'s thought - answer: "
                  + bestThought->answer + ", result: "
                  + std::to_string(bestThought->result) + ", period: "
                  + std::to_string(bestThought->period.count()));
    return bestThought;
}
