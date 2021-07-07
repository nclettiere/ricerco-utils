#include <Project/Project.hpp>
#include <Structure/ProjectStructure.hpp>

#include <iostream>
#include <string>

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/system/error_code.hpp>

#include <rus_config.hpp>

namespace rus
{
    Project::Project()
    {
        GenerateProjectUUID();
    }

    Project::Project(std::string name, std::string description)
        : _name(name),
          _description(description)
    {
        GenerateProjectUUID();
    }

    Project::Project(const char *name, const char *description)
        : _name(name),
          _description(description)
    {
        GenerateProjectUUID();
    }

    Project::Project(std::u16string name, std::u16string description)
        : _name(name.c_str()),
          _description(description.c_str())
    {
        GenerateProjectUUID();
    }

    Project::~Project()
    {
    }

    void Project::GenerateProjectUUID()
    {
        boost::uuids::random_generator generator;
        _uuid = generator();
    }

    bool Project::CreateProject(boost::system::error_code &ec)
    {
        return rus::GenerateProjectStructure(*this, ec);
    }

    bool Project::CreateProject(const char *path, boost::system::error_code &ec)
    {
        return rus::GenerateProjectStructure(path, *this, ec);
    }
}