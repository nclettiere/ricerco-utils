#include <Project/Project.hpp>
#include <Structure/Structure.hpp>

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

    Project::Project(std::string _name, std::string _description, std::string _originalPath)
        : _name(_name),
          _description(_description),
          _originalPath(_originalPath)
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
        std::cout << "Creating Project" << std::endl;

        boost::system::error_code ec;

        if (rus::EnsureBaseStructure(ec))
        {
            std::cout << "GenerateBaseDirs Success" << std::endl;
        }
        else
        {
            std::cout << "GenerateBaseDirs Error: " << ec.message() << std::endl;
        }
    }
}