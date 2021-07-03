#include <Structure/ProjectStructure.hpp>

#include <iostream>

#include <nlohmann/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <boost/system/error_code.hpp>

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

    void GetProjectDirs(fs::path (&paths)[5], Project &project)
    {
        paths[0] = GetProjectDir(ProjectDir::Quests, project);
        paths[1] = GetProjectDir(ProjectDir::Scripts, project);
        paths[2] = GetProjectDir(ProjectDir::Dialogues, project);
        paths[3] = GetProjectDir(ProjectDir::Characters, project);
        paths[4] = GetProjectDir(ProjectDir::Items, project);
    }

    bool GenerateProjectStructure(Project &project)
    {
        std::vector<fs::path> discoverPaths;

        DiscoverProjects(discoverPaths, GetRicercoDir(RicercoDir::Projects));

        boost::system::error_code ec;

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

    bool CheckProjectIntegrity(Project &project)
    {
        return true;
    }
}