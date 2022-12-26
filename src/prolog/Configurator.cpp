#include "prolog/Configurator.hpp"

#include <iostream>

#include "config/Config.hpp"

namespace prolog
{

std::string config::LOG_FORMAT {"%L %D %T %Z %ID [%N](%F): %M"};
std::string config::DATE_FORMAT {"%Y-%m-%d"};

Configurator::Configurator()
{}

void Configurator::setLogFormat(std::string format)
{
    config::LOG_FORMAT = format;
}

void Configurator::setDateFormat(std::string format)
{
    config::DATE_FORMAT = format;
}

} // namespace prolog

