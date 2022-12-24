#include "log_object/Log.hpp"

#include <regex>

#include "enums/ELogLevel.hpp"

std::string DUMMY_MSG = "%L %D %T %Z %ID %N::%F %M";

namespace prolog::log_object
{

Log::Log(enums::ELogLevel level, std::string date, std::string func, std::string msg, std::string name,
        std::string threadId, std::string time, std::string zone)
    : level_(level)
    , date_(date)
    , func_(func)
    , msg_(msg)
    , name_(name)
    , threadId_(threadId)
    , time_(time)
    , zone_(zone)
{}

std::string Log::toString()
{
    auto log = DUMMY_MSG;
    log = std::regex_replace(log, std::regex("\\%L"), enums::logLevelToString(level_));
    log = std::regex_replace(log, std::regex("\\%M"), msg_);

    return log;
}

}  // namespace prolog::log_object
