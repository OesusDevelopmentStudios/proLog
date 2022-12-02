#pragma once

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

    void debug(const std::string& msg);
    void debug(const std::string& functionName, const std::string& name);
    void error(const std::string& msg);
    void error(const std::string& functionName, const std::string& name);
    void info(const std::string& msg);
    void info(const std::string& functionName, const std::string& name);
    void warning(const std::string& msg);
    void warning(const std::string& functionName, const std::string& name);
private:
    const std::string getCurrentTime();
    std::string makeMsg(enums::ELogLevel level, const std::string& msg, const std::string funcName="");
    void write(const std::string& msg);


    const std::string loggerName;
};

}  // namespace prolog
