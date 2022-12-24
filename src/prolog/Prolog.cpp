#include "prolog/Prolog.hpp"

#include <chrono>
#include <sstream>
#include <thread>

#include "enums/ELogLevel.hpp"
#include "log_object/Log.hpp"

namespace prolog
{

Prolog::Prolog(const std::string& name)
    : loggerName_("[" + name + "]")
{}

Prolog::~Prolog()
{}

void Prolog::debug(const std::string& funcName, const std::string& msg) const
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Debug, msg, funcName);
    write(log);
}

void Prolog::error(const std::string& funcName, const std::string& msg) const
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Error, msg, funcName);
    write(log);
}

void Prolog::info(const std::string& funcName, const std::string& msg) const
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Info, msg, funcName);
    write(log);
}

void Prolog::warning(const std::string& funcName, const std::string& msg) const
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Warning, msg, funcName);
    write(log);
}

const std::string Prolog::getCurrentTime() const
{
    auto timepoint = std::chrono::high_resolution_clock::now();
    auto coarse = std::chrono::system_clock::to_time_t(timepoint);
    auto fine = std::chrono::time_point_cast<std::chrono::microseconds>(timepoint);

    char buffer[sizeof("9999-12-31 ZONE 23:59:59.9999999")];
    std::snprintf(buffer + std::strftime(buffer, sizeof(buffer) - 3, "%Y-%m-%d %Z %H:%M:%S:", std::localtime(&coarse)),
        7, "%06lu", fine.time_since_epoch().count() % 1000000);

    return buffer;
}

log_object::Log Prolog::makeMsg(enums::ELogLevel level, const std::string& msg, const std::string funcName) const
{
    std::stringstream thread;
    thread << std::this_thread::get_id();
    auto threadId  = "<" + thread.str() + ">";

    return log_object::Log(level, "", "", funcName, msg, loggerName_, threadId, "");
    /*std::string log = "";
    log = log + enums::logLevelToString(level);
    log = log + " " + getCurrentTime();

    std::stringstream threadId;
    threadId << std::this_thread::get_id();
    log = log + " <" + threadId.str() + ">";

    if (funcName == "")
    {
        log = log + " " + loggerName + ": ";
    }
    else
    {
        log = log + " " + loggerName + "." + funcName + "(): ";
    }

    log = log + msg;

    return log;*/
}

void Prolog::write(log_object::Log msg) const
{
    std::cout << msg.toString() << std::endl;
}

}  // namespace prolog
