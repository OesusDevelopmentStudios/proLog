#include "log_object/Log.hpp"

namespace prolog::log_object
{

Log::Log(enums::ELogLevel level, std::string date, std::string func, std::string msg, std::string name,
        std::string threadId, std::string time)
    : level_(level)
    , date_(date)
    , func_(func)
    , msg_(msg)
    , name_(name)
    , threadId_(threadId)
    , time_(time)
{}

std::string Log::toString()
{
    return "";
}

}  // namespace prolog::log_object
