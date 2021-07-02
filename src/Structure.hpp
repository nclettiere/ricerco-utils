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

    enum class RicercoDir
    {
        Home,
        Projects,
        Cache
    };

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

    fs::path GetRicercoDir(RicercoDir ricercoDir)
    {
        fs::path base(GetHomeDir().c_str());
        fs::path dir;
        switch (ricercoDir)
        {
        case RicercoDir::Home:
            dir = fs::path(G_Path_RicercoBase);
            break;
        case RicercoDir::Projects:
            dir = fs::path(G_Path_RicercoProjectsBase);
            break;
        case RicercoDir::Cache:
            dir = fs::path(G_Path_RicercoCacheBase);
            break;
        }
        return base / dir;
    }

    /**
    * Generates the necessary directories and files for using the Ricerco application.
    * 
    * NOTE: Windows only.
    * TODO: Add MacOS and Linux support.
    *
    * @return Returns true if all files and folders are created correctly. Otherwise, returns false.
    */
    bool GenerateBaseDirs(boost::system::error_code &ec) noexcept
    {
        fs::path homeDir = GetRicercoDir(RicercoDir::Home);
        fs::path projectsDir = GetRicercoDir(RicercoDir::Projects);
        fs::path cacheDir = GetRicercoDir(RicercoDir::Cache);

        if (homeDir.empty() || projectsDir.empty())
        {
            bool homeExist = fs::exists(homeDir),
                 projectsExist = fs::exists(projectsDir),
                 cacheExist = fs::exists(cacheDir);

            if (!homeExist && !fs::create_directories(homeDir, ec))
                return false;
            if (!projectsExist && !fs::create_directories(projectsDir, ec))
                return false;
            if (!cacheExist && !fs::create_directories(cacheDir, ec))
                return false;
            return true;
        }

        return false;
    }
} // END namespace: rus