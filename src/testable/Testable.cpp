#include "testable/Testable.hpp"

namespace prolog::testable
{

Testable::Testable()
{}

Testable::~Testable()
{}

void Testable::start_test()
{
    info_logger();
    debbug_logger();
    error_logger();
    warning_logger();
}

void Testable::info_logger()
{}

void Testable::debbug_logger()
{}

void Testable::error_logger()
{}

void Testable::warning_logger()
{}

}  // namespace prolog::testable
