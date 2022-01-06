#pragma once

#include <rus_config.hpp>

#include <string>
#include <stdlib.h>

namespace rus
{
    enum class RicercoDir
    {
        Home,
        Projects,
        Cache
    };

    static std::string GetHomeDir();
    //fs::path GetRicercoDir(RicercoDir ricercoDir);
    //bool EnsureBaseStructure(boost::system::error_code &ec);
}