#pragma once

#include <string>
#include <vector>
#include <iostream>

#include <Structure/Structure.hpp>
#include <Project/Project.hpp>

#include <boost/range/iterator_range.hpp>

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
    fs::path GetUserProjectBaseDefaultDir(Project &project);
    bool GenerateProjectStructure(Project &project, boost::system::error_code &ec);
    bool CheckProjectIntegrity(Project &project);

    static void DiscoverProjects(std::vector<fs::path> &projectPaths, fs::path &whereToFind);
} // namespace rus