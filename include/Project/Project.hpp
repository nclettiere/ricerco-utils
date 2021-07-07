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
        std::wstring _name;
        std::wstring _description;

    public:
        Project();
        Project(std::string name, std::string description);
        Project(std::u16string name, std::u16string description);
        Project(const char *name, const char *description);
        ~Project();

    public:
        std::string GetName() { return _name; }
        std::string GetDescription() { return _description; }

        void SetName(std::string &name) { _name = name; }
        void SetDescription(std::string &description) { _description = description; }
    protected:
        void GenerateProjectUUID();

    public:
        bool CreateProject(boost::system::error_code &ec);
        bool CreateProject(const char *path, boost::system::error_code &ec);
    };
}