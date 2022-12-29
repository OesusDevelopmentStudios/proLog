#pragma once

#include <vector>

namespace prolog
{

namespace log
{
class Log;
}  // namespace log

namespace server
{

class Server
{
public:
    Server();
    Server(Server& server) = delete;
    ~Server();

    void start();
    
    void operator=(const Server& server) = delete;

private:
    std::vector<log::Log> storedLogs_;
};

}  // namespace prolog
}  // namespace server
