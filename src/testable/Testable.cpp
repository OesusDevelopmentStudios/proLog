#include "testable/Testable.hpp"

#include "prolog/Prolog.hpp"

namespace prolog::testable
{

namespace
{
Prolog logger("Testable");
}  // namespace

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
{
}

void Testable::debbug_logger()
{
}

void Testable::error_logger()
{
    logger.error(__func__, "message");// logger << __func__ << "testing3";
    logger.error("critical failure!");
}

void Testable::warning_logger()
{
    //logger << __func__ << "testing4";
}

}  // namespace prolog::testable
