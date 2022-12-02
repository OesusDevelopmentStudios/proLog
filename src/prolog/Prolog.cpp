#include "prolog/Prolog.hpp"

#include <chrono>

#include "enums/ELogLevel.hpp"

namespace prolog
{

namespace
{

std::string logLevelToString(enums::ELogLevel level)
{
    switch (level)
    {
        case enums::ELogLevel::ELogLevel_Debbug:
            return "[DEBBUG]";
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

const std::string Prolog::getCurrentTime()
{
    #if __cplusplus >= 202002L
    std::cout << "C++20 support prese"
    #endif

    // std::chrono::zoned_time time{
    //    std::chrono::current_zone(), std::chrono::system_clock::now()};


    return "time";
}

std::string Prolog::makeMsg(enums::ELogLevel level, const std::string& msg, const std::string funcName)
{
    std::string log = "";
    log = log + logLevelToString(level);
    log = log + " " + getCurrentTime();
    auto logLevel = logLevelToString(level);
    if (funcName == "")
    {
        log = log + " " + loggerName + ": ";
    }
    else
    {
        log = log + " " + loggerName + ".[" + funcName + "]: ";
    }

    log = log + msg;

    return log;
}

void Prolog::write(const std::string& msg)
{
    std::cout << msg << std::endl;
}

}  // namespace prolog
