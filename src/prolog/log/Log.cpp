#include "log/Log.hpp"

#include <regex>
#include <iostream>

#include "config/config.hpp"
#include "enums/ELogLevel.hpp"

namespace prolog::log
{

Log::Log(const enums::ELogLevel& level, const std::string& date, const std::string& func, const std::string& msg,
    const std::string& name, const std::string& threadId, const std::string& time, const std::string& zone)
    : level_(level)
    , date_(date)
    , func_(func)
    , msg_(msg)
    , name_(name)
    , threadId_(threadId)
    , time_(time)
    , zone_(zone)
{}

const std::string Log::toString() const
{
    auto log = config::LOG_FORMAT;
    log = std::regex_replace(log, std::regex("\\%D"), date_);
    log = std::regex_replace(log, std::regex("\\%F"), func_);
    log = std::regex_replace(log, std::regex("\\%ID"), threadId_);
    log = std::regex_replace(log, std::regex("\\%L"), enums::logLevelToString(level_));
    log = std::regex_replace(log, std::regex("\\%M"), msg_);
    log = std::regex_replace(log, std::regex("\\%N"), name_);
    log = std::regex_replace(log, std::regex("\\%T"), time_);
    log = std::regex_replace(log, std::regex("\\%Z"), zone_);

    return log;
}

}  // namespace prolog::log
