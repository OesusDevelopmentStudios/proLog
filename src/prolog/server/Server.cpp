#include "server/Server.hpp"

#include <iostream>

#include "config/Config.hpp"
#include "log/Log.hpp"
#include "server/fwd.hpp"

#include <thread>
#include <sstream>

namespace prolog::server
{

Server::Server()
    : storedLogs_(std::vector<log::Log>())
{}

Server::~Server()
{}

void Server::start()
{
    enabled_ = true;
    run();
}

void Server::run()
{
    while (enabled_)
    {
        processLogs();
    }
}

void Server::addLog(log::Log log)
{
    if (not server::isInitilized)
    {
        std::cout << "[CONF ERROR] Prolog not initlized, log won't be processed!" << std::endl;
        return;
    }

    std::unique_lock<std::mutex> lock(storedLogsMutex_);
    storedLogs_.push_back(log);
    lock.unlock();

    if (not config::USE_THREADS)
    {
        processLogs();
    }
}

void Server::write(const log::Log& msg)
{
    std::cout << msg.toString() << std::endl;
}

void Server::processLogs()
{
    std::unique_lock<std::mutex> lock(storedLogsMutex_);
    std::vector<log::Log> logs = storedLogs_;
    storedLogs_.clear();
    lock.unlock();

    for (const auto log : logs)
    {
        if (config::VERBOSE) write(log);
    }
}

void Server::stop()
{
    enabled_ = false;
    processLogs();
}

}  // namesapce prolog::server
