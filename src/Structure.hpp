#pragma once

#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>

#include "rus_config.hpp"

namespace rus
{
    namespace fs = boost::filesystem;

    enum class RicercoDir { Home, Projects, Cache };

    /**
    * Gets the home dir of the current user.
    *
    * @return The current homedir of the user. May return an empty string if the environment variable is not found.
    */
    std::string GetHomeDir()
    {
        if (getenv(G_homeVar) == NULL)
            return "";
        return std::string(getenv(G_homeVar));
    }

    fs::path GetAppHomeDir()
    {
        fs::path home(GetHomeDir().c_str());
        fs::path base(G_Path_RicercoBase);

        fs::path full_path = home / base;

        printf("GetAppUserDir(): %s\n", full_path.string().c_str());

        return full_path;
    }

    fs::path GetAppHomeProjectsDir()
    {
        fs::path home(GetHomeDir().c_str());
        fs::path projects_base(G_Path_RicercoProjectsBase);

        fs::path full_path = home / base;

        printf("GetAppUserDir(): %s\n", full_path.string().c_str());

        return full_path;
    }

    /**
    * Generates the necessary directories and files for using the Ricerco application.
    *
    * @return Returns true if all files and folders are created correctly. Otherwise, returns false.
    */
    bool GenerateBaseDirs(boost::system::error_code &ec) noexcept
    {
        std::string homeDir = GetHomeDir();

        if (!homeDir.empty() && fs::exists(homeDir))
        {
            if (fs::create_directory(GetAppHomeDir(), ec))
            {
                if (fs::create_directories(GetAppHomeDir(), ec))
                {
                    return true;
                }
            }
        }

        return false;
    }
} // END namespace: rus