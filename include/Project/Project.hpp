#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>

namespace rus
{
    using namespace boost::uuids;

    class Project
    {
    public:
        Project();
        Project(std::string _name, std::string _description, std::string _originalPath);
        ~Project();

    private:
        uuid _uuid;
        std::string _name;
        std::string _description;
        std::string _originalPath;

    protected:
        void GenerateProjectUUID();

    public:
        static bool CreateProject();
    };
}