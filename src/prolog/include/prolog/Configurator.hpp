#pragma once

#include <string>

namespace prolog
{

class Configurator
{
public:
    Configurator();

    void setDateFormat(const std::string& format);
    void setLogFormat(const std::string& format);
    void setLogsPerFile(const uint16_t& limit);
    void setUseThreads(const bool& useThreads);
};

}  // namespace prolog
