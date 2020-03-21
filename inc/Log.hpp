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

class Log {
    std::mutex m_;
    std::condition_variable nonEmpty_;
    std::deque<LogEvent> queue_;
    
    std::string addLevelFlag(LogLevel lvl); // Returns prefix string for proper log level
    void addEvent(LogEvent rec);            // Adds event to queue
public:
    Log();
    ~Log();

    void processEvent();                    // Takes log messege from queue and prints it
    void logInfo(std::string text);         // Shows progress of execution
    void logDebug(std::string text);        // Shows additional data for debugging
    void logError(std::string text);        // Show errors messeges
};
