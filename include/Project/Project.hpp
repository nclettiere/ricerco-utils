#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace rus
{
    using namespace boost::uuids;

    class Project
    {

    private:
        uuid _uuid;
        std::string _name;
        std::string _description;

    public:
        Project();
        Project(std::string _name, std::string _description);
        ~Project();

    public:
        std::string GetName() { return _name; }
        std::string GetDescription() { return _description; }

        void SetName(std::string &name) { _name = name; }
        void SetDescription(std::string &description) { _description = description; }

    protected:
        void GenerateProjectUUID();

    public:
        bool CreateProject();
    };
}