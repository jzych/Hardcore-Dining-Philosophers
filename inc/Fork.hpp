#pragma once
#include <mutex>

struct Fork {
   std::mutex mutex;
};
