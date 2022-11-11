#pragma once

namespace prolog::testable
{

class Testable
{
public:
    Testable();
    ~Testable();

    void start_test();

private: 
    void info_logger();
    void debbug_logger();
    void error_logger();
    void warning_logger();
};

}  // namespace prolog::testable
