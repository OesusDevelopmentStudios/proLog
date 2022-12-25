#pragma once

#include <string>

namespace prolog
{

namespace enums
{
enum class ELogLevel;
}  // namespace enums

namespace log
{

class Log
{
public:
    //Log() = delete;
    Log(enums::ELogLevel level, std::string date, std::string func, std::string msg, std::string name,
        std::string threadId, std::string time, std::string zone);

    std::string toString();

private:
    enums::ELogLevel level_;
    std::string date_; 
    std::string func_;
    std::string msg_;
    std::string name_;
    std::string threadId_;
    std::string time_;
    std::string zone_;
};

}  // namespace log
}  // namespace prolog
