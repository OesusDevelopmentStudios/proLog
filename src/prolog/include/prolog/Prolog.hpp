#pragma once

#include <cstdarg>
#include <iostream>
#include <string>

namespace prolog
{

namespace enums
{
enum class ELogLevel;
}  // namespace enums

class Prolog
{
public:
    Prolog(const std::string& name);
    Prolog(Prolog& prolog);
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
    const std::string getCurrentTime() const;
    std::string makeMsg(enums::ELogLevel level, const std::string& msg, const std::string funcName="") const;
    void write(const std::string& msg) const;


    const std::string loggerName;
};

}  // namespace prolog
