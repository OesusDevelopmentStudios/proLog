#pragma once

#include <string>

namespace prolog
{

class Configurator
{
public:
    Configurator();

    void setLogFormat(std::string format);
    void setDateFormat(std::string format);
};

}  // namespace prolog
