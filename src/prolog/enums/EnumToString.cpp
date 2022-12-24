#include "enums/ELogLevel.hpp"

namespace prolog::enums
{

const std::string logLevelToString(enums::ELogLevel level)
{
    switch (level)
    {
        case enums::ELogLevel::ELogLevel_Debug:
            return "[DEBUG]";
        case enums::ELogLevel::ELogLevel_Info:
            return "[INFO]";
        case enums::ELogLevel::ELogLevel_Warning:
            return "[WARNING]";
        case enums::ELogLevel::ELogLevel_Error:
            return "[ERROR]";
    }

    return "";
}

}  // namespace prolog::enums 
