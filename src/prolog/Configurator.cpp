#include "prolog/Configurator.hpp"

#include <iostream>

#include "config/Config.hpp"

namespace prolog
{

bool config::USE_THREADS {true};
uint16_t config::LOGS_PER_FILE {10000};
std::string config::LOG_FORMAT {"%L %D %T %Z %ID [%N](%F): %M"};
std::string config::DATE_FORMAT {"%Y-%m-%d"};

Configurator::Configurator()
{}

void Configurator::setDateFormat(const std::string& format)
{
    config::DATE_FORMAT = format;
}

void Configurator::setLogFormat(const std::string& format)
{
    config::LOG_FORMAT = format;
}

void Configurator::setLogsPerFile(const uint16_t& limit)
{
    config::LOGS_PER_FILE = limit;
}

void Configurator::setUseThreads(const bool& useThreads)
{
    config::USE_THREADS = useThreads;   
}

} // namespace prolog

