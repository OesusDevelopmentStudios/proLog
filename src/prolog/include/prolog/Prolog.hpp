#pragma once

#include <cstdarg>
#include <string>
#include <vector>

namespace prolog
{

namespace enums
{
enum class ELogLevel;
}  // namespace enums

namespace log
{
class Log;
}  // namespace log

class Prolog
{
public:
    explicit Prolog(const std::string& name);
    explicit Prolog(Prolog& prolog);
    ~Prolog();

    void debug(const std::string& msg) const { debug("", msg); }
    void error(const std::string& msg) const { error("", msg); }
    void info(const std::string& msg) const { info("", msg); }
    void warning(const std::string& msg) const { warning("", msg); }

    void debug(const std::string& functionName, const std::string& name) const;
    void error(const std::string& functionName, const std::string& name) const;
    void info(const std::string& functionName, const std::string& name) const;
    void warning(const std::string& functionName, const std::string& name) const;

private:
    const std::vector<std::string> getCurrentTime() const;
    log::Log makeMsg(enums::ELogLevel level, const std::string& msg, const std::string funcName="") const;

    const std::string loggerName_;
};

}  // namespace prolog
