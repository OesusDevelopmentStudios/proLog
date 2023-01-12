#include "prolog/Prolog.hpp"

#include <chrono>
#include <sstream>
#include <thread>

#include "config/Config.hpp"
#include "enums/ELogLevel.hpp"
#include "log/Log.hpp"
#include "server/fwd.hpp"

namespace prolog
{

Prolog::Prolog(const std::string& name)
    : loggerName_(name)
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

const std::vector<std::string> Prolog::getCurrentTime() const
{
    auto timepoint = std::chrono::high_resolution_clock::now();
    auto coarse = std::chrono::system_clock::to_time_t(timepoint);
    auto fine = std::chrono::time_point_cast<std::chrono::microseconds>(timepoint);

    char date [sizeof(config::DATE_FORMAT)];
    char zone [sizeof("ZONE")];
    char time [sizeof("23:59:59.9999999")];

    std::strftime(std::data(date), std::size(date), config::DATE_FORMAT.c_str(), std::localtime(&coarse));
    std::strftime(std::data(zone), std::size(zone), "%Z", std::localtime(&coarse));
    std::snprintf(time + std::strftime(time, sizeof(time) - 3, "%H:%M:%S:", std::localtime(&coarse)),
        7, "%06lu", fine.time_since_epoch().count() % 1000000);

    return {date, zone, time};
}

log::Log Prolog::makeMsg(enums::ELogLevel level, const std::string& msg, const std::string funcName) const
{
    const auto time = getCurrentTime();
    std::stringstream thread;
    thread << std::this_thread::get_id();
    auto threadId  = "<" + thread.str() + ">";

    return log::Log(level, time[0], funcName, msg, loggerName_, threadId, time[2], time[1]);
}

void Prolog::write(log::Log msg) const
{
    std::cout << msg.toString() << std::endl;
}

}  // namespace prolog
