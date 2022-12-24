#pragma once

#include <string>

namespace prolog::enums
{

enum class ELogLevel
{
    ELogLevel_Debug,
    ELogLevel_Info,
    ELogLevel_Warning,
    ELogLevel_Error
};

const std::string logLevelToString(enums::ELogLevel level);

}  // namespace prolog::enums
