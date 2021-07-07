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

    void GetProjectDirs(fs::path (&paths)[5], Project &project);
    void GetProjectDirs(fs::path (&paths)[5], fs::path &projPath);
    fs::path GetProjectDir(ProjectDir ProjectDir, Project &project);
    fs::path GetProjectDir(ProjectDir projectDir, fs::path &projPath);
    fs::path GetUserProjectBaseDefaultDir(Project &project);
    bool GenerateProjectStructure(Project &project, boost::system::error_code &ec);
    bool GenerateProjectStructure(const char *saveToPath, Project &project, boost::system::error_code &ec);
    bool CheckProjectIntegrity(Project &project);

    static void DiscoverProjects(std::vector<fs::path> &projectPaths, fs::path &whereToFind);
} // namespace rus