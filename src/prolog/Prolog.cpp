#include "prolog/Prolog.hpp"

#include <chrono>
#include <thread>

#include "enums/ELogLevel.hpp"

namespace prolog
{

namespace
{

std::string logLevelToString(enums::ELogLevel level)
{
    switch (level)
    {
        case enums::ELogLevel::ELogLevel_Debug:
            return "[DEBUG]";
        case enums::ELogLevel::ELogLevel_Info:
            return "[INFO]";
        case enums::ELogLevel::ELogLevel_Warning:
            return "[WARNING]";
        case enums::ELogLevel::ELogLevel_Error:
            return "[ERROR]";
    }

    return "";
}

}  // namespace

Prolog::Prolog(const std::string& name)
    : loggerName("[" + name + "]")
{}

Prolog::~Prolog()
{}

void Prolog::debug(const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Debug, msg);
    write(log);
}

void Prolog::debug(const std::string& funcName, const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Debug, msg, funcName);
    write(log);
}

void Prolog::error(const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Error, msg);
    write(log);
}

void Prolog::error(const std::string& funcName, const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Error, msg, funcName);
    write(log);
}

void Prolog::info(const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Info, msg);
    write(log);
}

void Prolog::info(const std::string& funcName, const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Info, msg, funcName);
    write(log);
}

void Prolog::warning(const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Warning, msg);
    write(log);
}

void Prolog::warning(const std::string& funcName, const std::string& msg)
{
    const auto log = makeMsg(enums::ELogLevel::ELogLevel_Warning, msg, funcName);
    write(log);
}

const std::string Prolog::getCurrentTime()
{
    auto timepoint = std::chrono::system_clock::now();
    auto coarse = std::chrono::system_clock::to_time_t(timepoint);
    auto fine = std::chrono::time_point_cast<std::chrono::milliseconds>(timepoint);

    char buffer[sizeof("9999-12-31 ZONE 23:59:59.999")];
    std::snprintf(buffer + std::strftime(buffer, sizeof(buffer) - 3, "%Y-%m-%d %Z %H:%M:%S:", std::localtime(&coarse)),
        4, "%03lu", fine.time_since_epoch().count() % 1000);

    return buffer;
}

std::string Prolog::makeMsg(enums::ELogLevel level, const std::string& msg, const std::string funcName)
{
    std::string log = "";
    log = log + logLevelToString(level);
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

    return log;
}

void Prolog::write(const std::string& msg)
{
    std::cout << msg << std::endl;
}

}  // namespace prolog
