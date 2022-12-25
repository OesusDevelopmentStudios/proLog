#pragma once

#include <string>

namespace prolog::config
{
    static std::string LOG_FORMAT {"%L %D %T %Z %ID [%N]::[%F] %M"};
    static std::string DATE_FORMAT {"%Y-%m-%d"};
}  // namespace prolog::config
