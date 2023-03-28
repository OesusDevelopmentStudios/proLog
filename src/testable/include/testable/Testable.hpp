#pragma once

#include <memory>

namespace prolog
{

class Configurator;

namespace testable
{

class Testable
{
public:
    Testable();
    ~Testable();

    void start_test();

private: 
    void info_logger();
    void debug_logger();
    void error_logger();
    void warning_logger();

    std::unique_ptr<Configurator> config_;
};

}  // namespace testable
}  // namespace prolog
