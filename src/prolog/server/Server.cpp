#include "server/Server.hpp"

#include <iostream>

#include "config/Config.hpp"
#include "log/Log.hpp"

#include <thread>
#include <sstream>

namespace prolog::server
{

Server::Server()
{}

Server::~Server()
{
    stop();
}

void Server::start()
{
    enabled_ = true;
    run();
}

void Server::run()
{
    while (enabled_)
    {}
}

void Server::addLog(log::Log log)
{
    storedLogs_.push_back(log);

    if (config::VERBOSE)
    {
        write(log);
    }
}

void Server::write(const log::Log& msg)
{
    std::stringstream thread;
    thread << std::this_thread::get_id();
    auto threadId  = "<" + thread.str() + ">";

    std::cout << "Log from thread " << threadId << std::endl;

    std::cout << msg.toString() << std::endl;
}

void Server::stop()
{
    enabled_ = false;
}

}  // namesapce prolog::server
