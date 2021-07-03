#pragma once

#include <Structure/Structure.hpp>
#include <Project/Project.hpp>

namespace rus
{
    enum class ProjectDir
    {
        Quests,
        Scripts,
        Dialogues,
        Characters,
        Items
    };

    static fs::path GetProjectDir(ProjectDir projectDir, Project &project);
    static void GetProjectDirs(fs::path (&paths)[5], Project &project);
    static fs::path GetProjectDir(ProjectDir ProjectDir, Project &project);
    static bool GenerateProjectStructure(Project &ec);
    static bool CheckProjectIntegrity(Project &ec);
}