#pragma once

#include <string>

namespace prolog::log_object
{

namespace enums
{
enum class ELogLevel;
}  // namespace enums

class Log
{
public:
    Log() = delete;
    Log(enums::ELogLevel level, std::string date, std::string func, std::string msg, std::string name,
        std::string threadId, std::string time);

    std::string toString();

private:
    enums::ELogLevel level_;
    std::string date_; 
    std::string func_;
    std::string msg_;
    std::string name_;
    std::string threadId_:
    std::string time_;
};

}  // namespace prolog::log_object
