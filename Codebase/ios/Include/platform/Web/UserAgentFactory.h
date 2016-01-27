#pragma once

#include <string>
#include "AppInfo.h"

namespace Eegeo
{
    namespace Web
    {
        std::string CreateUserAgent(const AppInfo& info);
    }
}