#include "prolog/Configurator.hpp"

#include <iostream>
#include <memory>

#include "config/Config.hpp"
#include "server/fwd.hpp"

namespace prolog
{

bool config::USE_THREADS {true};
uint16_t config::LOGS_PER_FILE {10000};
std::string config::LOG_FORMAT {"%L %D %T %Z %ID [%N](%F): %M"};
std::string config::DATE_FORMAT {"%Y-%m-%d"};

bool server::isInitilized {false};
server::Server server::logServer {Server()};

Configurator::Configurator()
{}

Configurator::~Configurator()
{
    if (config::USE_THREADS)
    {
        server::logServer.stop();

        if (serverThread_.joinable())
        {
            serverThread_.join();
        }
    }
}

void Configurator::initilize()
{
    if (config::USE_THREADS)
    {
        serverThread_ = std::thread(&server::Server::start, &server::logServer);
        serverThread_.detach();
    }

    server::isInitilized = true;
}

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

