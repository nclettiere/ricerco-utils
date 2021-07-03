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

    fs::path GetProjectDir(ProjectDir projectDir, Project &project);
    void GetProjectDirs(fs::path (&paths)[5], Project &project);
    fs::path GetProjectDir(ProjectDir ProjectDir, Project &project);
    bool GenerateProjectStructure(Project &project);
    bool CheckProjectIntegrity(Project &project);
}