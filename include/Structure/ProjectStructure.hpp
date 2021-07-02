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

    static fs::path GetProjectDir(ProjectDir ProjectDir);
    static bool GenerateProjectStructure(Project &ec);
    static bool CheckProjectIntegrity(Project &ec);
}