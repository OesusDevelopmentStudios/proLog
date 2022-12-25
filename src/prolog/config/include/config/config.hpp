#pragma once

#include <string>

namespace prolog::config
{
    static std::string LOG_FORMAT {"%L %D %T %Z %ID [%N]::[%F] %M"};
    static std::string dateFormat {"%Y-%m-%d %Z %H:%M:%S:"};
    static std::string zoneFomrat {};

}  // namespace prolog::config
