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
    bool GenerateProjectStructure(Project &project);
    bool CheckProjectIntegrity(Project &project);

    static void DiscoverProjects(std::vector<fs::path> &projectPaths, fs::path &whereToFind)
    {
        if (is_directory(whereToFind))
        {
            std::cout << whereToFind << " is a directory containing:\n";

            for (auto &entry : boost::make_iterator_range(fs::directory_iterator(whereToFind), {}))
            {
                fs::path pEntry(entry);

                //while(fs::is_directory())
                //if(fs::is_directory(entry)) {
                //}
                std::cout << entry << "\n";
            }
        }
    }
} // namespace rus