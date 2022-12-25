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
    Log(const enums::ELogLevel& level, const std::string& date, const std::string& func, const std::string& msg,
        const std::string& name, const std::string& threadId, const std::string& time, const std::string& zone);

    const std::string toString() const;

private:
    const enums::ELogLevel level_;
    const std::string date_; 
    const std::string func_;
    const std::string msg_;
    const std::string name_;
    const std::string threadId_;
    const std::string time_;
    const std::string zone_;
};

}  // namespace log
}  // namespace prolog
