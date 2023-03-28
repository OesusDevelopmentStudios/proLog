#pragma once

#include <string>

namespace prolog::config
{
    extern bool USE_THREADS;
    extern bool VERBOSE;
    extern uint16_t LOGS_PER_FILE;
    extern std::string DATE_FORMAT;
    extern std::string LOG_FORMAT;
}  // namespace prolog::config
