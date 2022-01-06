#pragma once

// TODO: Delete this file (not suppo)
namespace rus
{
	class Project
	{
	};
}

//#include <string>
//#include <boost/uuid/uuid.hpp>
//#include <boost/filesystem.hpp>
//
//namespace fs = boost::filesystem;
//
//namespace rus
//{
//    using namespace boost::uuids;
//
//    class Project
//    {
//
//    private:
//        uuid _uuid;
//        std::wstring _name;
//        std::wstring _description;
//
//    public:
//        Project();
//        Project(std::wstring name, std::wstring description);
//        ~Project();
//
//    public:
//        std::wstring & GetName() { return _name; }
//        std::wstring & GetDescription() { return _description; }
//
//        void SetName(std::wstring &name) { _name = name; }
//        void SetDescription(std::wstring &description) { _description = description; }
//    protected:
//        void GenerateProjectUUID();
//
//    public:
//        bool CreateProject(boost::system::error_code &ec);
//        bool CreateProject(std::wstring &path, boost::system::error_code &ec);
//    };
//}