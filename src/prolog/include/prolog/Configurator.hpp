#pragma once

#include <string>
#include <thread>

namespace prolog
{

class Configurator
{
public:
    Configurator();
    ~Configurator();

    void initilize();
    void setDateFormat(const std::string& format);
    void setLogFormat(const std::string& format);
    void setLogsPerFile(const uint16_t& limit);
    void setUseThreads(const bool& useThreads);

private:
    std::thread serverThread_;
};

}  // namespace prolog
