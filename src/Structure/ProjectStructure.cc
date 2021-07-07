#include <Structure/ProjectStructure.hpp>

#include <iostream>

#include <nlohmann/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/error_category.hpp>
#include <boost/system/errc.hpp>

namespace rus
{
    fs::path GetProjectDir(ProjectDir projectDir, Project &project)
    {
        fs::path base = GetRicercoDir(RicercoDir::Projects);
        fs::path selectedPath;

        switch (projectDir)
        {
        case ProjectDir::Quests:
            selectedPath = "Quests";
            break;
        case ProjectDir::Scripts:
            selectedPath = "Scripts";
            break;
        case ProjectDir::Dialogues:
            selectedPath = "Dialogues";
            break;
        case ProjectDir::Characters:
            selectedPath = "Characters";
            break;
        case ProjectDir::Items:
            selectedPath = "Items";
            break;
        }
        return base / fs::path(project.GetName()) / selectedPath;
    }

    fs::path GetProjectDir(ProjectDir projectDir, fs::path &projPath)
    {
        fs::path selectedPath;

        switch (projectDir)
        {
        case ProjectDir::Quests:
            selectedPath = "Quests";
            break;
        case ProjectDir::Scripts:
            selectedPath = "Scripts";
            break;
        case ProjectDir::Dialogues:
            selectedPath = "Dialogues";
            break;
        case ProjectDir::Characters:
            selectedPath = "Characters";
            break;
        case ProjectDir::Items:
            selectedPath = "Items";
            break;
        }
        return projPath / selectedPath;
    }

    fs::path GetUserProjectBaseDefaultDir(Project &project)
    {
        fs::path base = GetRicercoDir(RicercoDir::Projects);
        return base / fs::path(project.GetName());
    }

    void GetProjectDirs(fs::path (&paths)[5], Project &project)
    {
        paths[0] = GetProjectDir(ProjectDir::Quests, project);
        paths[1] = GetProjectDir(ProjectDir::Scripts, project);
        paths[2] = GetProjectDir(ProjectDir::Dialogues, project);
        paths[3] = GetProjectDir(ProjectDir::Characters, project);
        paths[4] = GetProjectDir(ProjectDir::Items, project);
    }

    void GetProjectDirs(fs::path (&paths)[5], fs::path &projPath)
    {
        paths[0] = GetProjectDir(ProjectDir::Quests, projPath);
        paths[1] = GetProjectDir(ProjectDir::Scripts, projPath);
        paths[2] = GetProjectDir(ProjectDir::Dialogues, projPath);
        paths[3] = GetProjectDir(ProjectDir::Characters, projPath);
        paths[4] = GetProjectDir(ProjectDir::Items, projPath);
    }

    bool GenerateProjectStructure(Project &project, boost::system::error_code &ec)
    {
        std::vector<fs::path> discoverPaths;
        DiscoverProjects(discoverPaths, GetRicercoDir(RicercoDir::Projects));

        for (auto it = begin(discoverPaths); it != end(discoverPaths); ++it)
        {
            // if there is already a project on the DEFAULT directory
            if (it->string().find(GetUserProjectBaseDefaultDir(project).string()) != std::string::npos)
            {
                ec.assign(boost::system::errc::file_exists, boost::system::generic_category());
                return false;
            }
        }

        fs::path projectPaths[5];
        GetProjectDirs(projectPaths, project);

        for (size_t i = 0; i < 5; i++)
        {
            if (!fs::create_directories(projectPaths[i], ec))
            {
                if (!fs::exists(projectPaths[i]))
                    return false;
            }
        }

        return true;
    }

    bool GenerateProjectStructure(const char *saveToPath, Project &project, boost::system::error_code &ec)
    {
        std::vector<fs::path> discoverPaths;
        fs::path saveTo(saveToPath);
        fs::path projPath(saveTo / project.GetName());

        DiscoverProjects(discoverPaths, saveTo);

        for (auto it = begin(discoverPaths); it != end(discoverPaths); ++it)
        {
            // if there is already a project on the DEFAULT directory
            if (it->string().find(projPath.string()) != std::string::npos)
            {
                ec.assign(boost::system::errc::file_exists, boost::system::generic_category());
                return false;
            }
        }

        fs::path projectPaths[5];
        GetProjectDirs(projectPaths, projPath);

        for (size_t i = 0; i < 5; i++)
        {
            if (!fs::create_directories(projectPaths[i], ec))
            {
                if (!fs::exists(projectPaths[i]))
                    return false;
            }
        }

        return true;
    }

    static void DiscoverProjects(std::vector<fs::path> &projectPaths, fs::path &whereToFind)
    {
        if (is_directory(whereToFind))
        {
            // For all folders in ...whereToFind
            for (auto &projectFolder : boost::make_iterator_range(fs::directory_iterator(whereToFind), {}))
            {
                if (is_directory(projectFolder))
                {
                    // Search for project entry file (.rop)
                    for (auto &pEntry : boost::make_iterator_range(fs::directory_iterator(projectFolder), {}))
                    {
                        if (fs::is_regular_file(pEntry) && fs::extension(pEntry) == ".rop")
                        {
                            projectPaths.push_back(pEntry);
                        }
                    }
                }
            }
        }
    }

    bool CheckProjectIntegrity(Project &project)
    {
        return true;
    }
}