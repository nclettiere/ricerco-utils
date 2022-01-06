#include <Structure/Structure.hpp>

namespace rus
{

    /**
    * Gets the home dir of the current user.
    *
    * @return The current homedir of the user. May return an empty string if the environment variable is not found.
    */
    std::string GetHomeDir()
    {
        std::string homeDir;
#ifdef _MSC_VER
        char *buf = nullptr;
        size_t sz = 0;
        if (_dupenv_s(&buf, &sz, G_homeVar.c_str()) == 0 && buf != nullptr)
        {
            homeDir = buf;
            free(buf);
        }
#else
        if (getenv(G_homeVar.c_str()) == NULL)
            return "";
        homeDir = getenv(G_homeVar.c_str());
#endif
        return homeDir;
    }

    //fs::path GetRicercoDir(RicercoDir ricercoDir)
    //{
    //    fs::path base(GetHomeDir().c_str());
    //    fs::path dir;
    //    switch (ricercoDir)
    //    {
    //    case RicercoDir::Home:
    //        dir = fs::path(".Ricerco");
    //        break;
    //    case RicercoDir::Projects:
    //        dir = fs::path(".Ricerco") / fs::path("Projects");
    //        break;
    //    case RicercoDir::Cache:
    //        dir = fs::path(".Ricerco") / fs::path("Cache");
    //        break;
    //    }
    //    return base / dir;
    //}

    /**
    * Generates the necessary directories and files for using the Ricerco application.
    *
    * Windows only.
    *
    * TODO: Add MacOS and Linux support.
    *
    * @return Returns true if all files and folders are created correctly. Otherwise, returns false.
    */
    //bool EnsureBaseStructure(boost::system::error_code &ec)
    //{
    //    fs::path homeDir = GetRicercoDir(RicercoDir::Home),
    //             projectsDir = GetRicercoDir(RicercoDir::Projects),
    //             cacheDir = GetRicercoDir(RicercoDir::Cache);
	//
    //    if (homeDir.empty() ||
    //        projectsDir.empty() ||
    //        cacheDir.empty())
    //        return false;
	//
    //    if (!fs::create_directory(homeDir, ec) &&
    //        !fs::exists(homeDir))
    //        return false;
    //    if (!fs::create_directory(projectsDir, ec) &&
    //        !fs::exists(projectsDir))
    //        return false;
    //    if (!fs::create_directory(cacheDir, ec) &&
    //        !fs::exists(cacheDir))
    //        return false;
    //    return true;
    //}
} // END namespace: rus