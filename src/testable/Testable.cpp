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
    debug_logger();
    error_logger();
    warning_logger();
}

void Testable::info_logger()
{
    logger.info(__func__, "you are now informed");
    logger.info("info but without func name");
}

void Testable::debug_logger()
{
    logger.debug(__func__, "urocze robaczki");
    logger.debug("creepy crawlies");
}

void Testable::error_logger()
{
    logger.error(__func__, "message");
    logger.error("some critical failure message!");
}

void Testable::warning_logger()
{
    logger.warning(__func__, "twoja stara");
    logger.warning("sra do gara");
}

}  // namespace prolog::testable
