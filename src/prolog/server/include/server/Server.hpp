#pragma once

#include <mutex>
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

    void addLog(log::Log log);
    void start();
    void stop();
    
    void operator=(const Server& server) = delete;

private:
    void processLogs();
    void run();
    void write(const log::Log& msg);

    bool enabled_;
    std::mutex storedLogsMutex_;
    std::vector<log::Log> storedLogs_;
};

}  // namespace prolog
}  // namespace server
