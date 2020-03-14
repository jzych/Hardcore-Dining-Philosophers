#pragma once
#include <deque>
#include <string>
#include <mutex>
#include <condition_variable>

#ifndef DEBUG
constexpr bool debug = false;
#else
constexpr bool debug = true;
#endif

enum class LogLevel {
    info,
    debug,
    error
};

struct LogEvent {
    LogLevel lvl;
    std::string data;
};

struct Log {
    std::mutex m_;
    std::condition_variable nonEmpty_;
    std::deque<LogEvent> queue_;

    void processEvent();
    std::string addLevelFlag(LogLevel lvl);
public:
    void addEvent(LogEvent rec);
};
