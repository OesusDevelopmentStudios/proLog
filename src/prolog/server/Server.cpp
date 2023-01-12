#include "server/Server.hpp"

#include "config/Config.hpp"
#include "log/Log.hpp"

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
    {

    }
}

void Server::stop()
{
    enabled_ = false;
}

}  // namesapce prolog::server
