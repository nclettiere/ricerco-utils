#include <Structure/ProjectStructure.hpp>
#include <Structure/Structure.hpp>

#include <iostream>

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
        boost::system::error_code ec;

        if (rus::EnsureBaseStructure(ec))
        {
            fs::path projectPaths[5];
            GetProjectDirs(projectPaths, project);

            std::cout << "Wakata" << std::endl;
            for (size_t i = 0; i < sizeof(projectPaths); i++)
            {
                std::cout << "Creating: " << projectPaths[i].string().c_str() << std::endl;
                fs::create_directories(projectPaths[i], ec);
            }
        }
        else
        {
            std::cout << "Could not ensure base directories\n"
                      << ec.message() << std::endl;
        }

        return false;
    }

    bool CheckProjectIntegrity(Project &project)
    {
        return true;
    }
}