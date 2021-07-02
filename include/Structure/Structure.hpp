#pragma once

#include <rus_config.hpp>

#include <string>
#include <stdlib.h>

#include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>

namespace fs = boost::filesystem;

namespace rus
{
    enum class RicercoDir
    {
        Home,
        Projects,
        Cache
    };

    static std::string GetHomeDir();
    static fs::path GetRicercoDir(RicercoDir ricercoDir);
    bool EnsureBaseStructure(boost::system::error_code &ec);
}