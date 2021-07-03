#include <Project/Project.hpp>
#include <Structure/ProjectStructure.hpp>

#include <iostream>

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/system/error_code.hpp>

namespace rus
{
    Project::Project()
    {
        GenerateProjectUUID();
    }

    Project::Project(std::string _name, std::string _description)
        : _name(_name),
          _description(_description)
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

    bool Project::CreateProject()
    {
        return rus::GenerateProjectStructure(*this);
    }
}