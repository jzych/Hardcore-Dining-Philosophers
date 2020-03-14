#include "Log.hpp"
#include <iostream>
#include <sstream>

std::string Log::addLevelFlag(LogLevel lvl) {
    if(lvl == LogLevel::error)
        return "ERROR: ";

    if(debug) {
        if(lvl == LogLevel::info)
            return "INFO:  ";
        if(lvl == LogLevel::debug)
            return "DEBUG: ";
    }

    return "";
}

void Log::addEvent(LogEvent rec) {
    std::unique_lock<std::mutex> l(m_);
    queue_.push_front(rec);
    nonEmpty_.notify_all();
}

void Log::processEvent() {
    std::unique_lock<std::mutex> l(m_);
    auto hasData = [&]{ return not queue_.empty(); };
    nonEmpty_.wait(l, hasData);

    std::stringstream output;
    auto record = queue_.back();
    queue_.pop_back();

    output << addLevelFlag(record.lvl);
    output << record.data << "\n";

    std::cout << output.str();
}

void Log::logInfo(std::string text) {
    LogEvent evt{LogLevel::info, text};
    addEvent(evt);
}

void Log::logDebug(std::string text) {
    if(debug) {
        LogEvent evt{LogLevel::debug, text};
        addEvent(evt);
    }
}

void Log::logError(std::string text) {
    LogEvent evt{LogLevel::error, text};
    addEvent(evt);
}
