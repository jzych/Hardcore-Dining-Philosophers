#pragma once
#include <queue>
#include <string>

enum class LogLevel {
    info,
    debug,
    error
};

struct LogRecord {
    LogLevel lvl;
    std::string data;
};

struct Log {
    std::queue<LogRecord> queue;

    void addRecord(LogRecord rec);
};
