#include "testable/Testable.hpp"

#include "prolog/Configurator.hpp"
#include "prolog/Prolog.hpp"

namespace prolog::testable
{

namespace
{
Prolog logger("Testable");
}  // namespace

Testable::Testable()
    : config_(std::make_unique<Configurator>())
{}

Testable::~Testable()
{}

void Testable::start_test()
{
    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for(dura);

    config_->initilize();

    std::this_thread::sleep_for(dura);
    info_logger();
    std::this_thread::sleep_for(dura);
    debug_logger();
    std::this_thread::sleep_for(dura);

    config_->setDateFormat("%d:%m %Yr.");

    error_logger();
    std::this_thread::sleep_for(dura);
    warning_logger();
    std::this_thread::sleep_for(dura);
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
