#include <napi.h>
#include <rus_config.hpp>

#ifdef RUS_WIN
namespace rus
{
    /**
     *  @brief Creates a new Ricerco project.
     *
     * @param info A dictionary containing Name, Description and optionally a path.
     * @param info If the path is omitted, it will use the default projects path on the user home directory.
     * @return [MaybeError] (JS Boolean) If the project is created successfully returns true.
     * @author Nicolas Cabrera Lettiere
     */
    Napi::Value CreateProject(const Napi::CallbackInfo &info);

    /**
     *  @brief Searches for projects inside a directory. Specifically for .rco project files.
     *
     * @param info (Optional) A JS string containing the desired path to search for projects.
     * @param info If the path is omitted, it will use the default projects path on the user home directory.
     * @return [MaybeError] (JS String Array) All projects PATHS located in this directory.
     * @author Nicolas Cabrera Lettiere
     */
    Napi::Value DiscoverProjects(const Napi::CallbackInfo &info);

    /**
     *  @brief Checks if a project with certain name and path can be placed and created in a directory.
     *
     * @param info The first argument MUST contain the project name.
     * @param info (Optional) The second argument should be the project path. This can be ommited if you want to use the default directory.
     * @return (JS String Array) All projects PATHS located in this directory.
     * @author Nicolas Cabrera Lettiere
     */
    Napi::Value IsProjectAvailable(const Napi::CallbackInfo &info);

    /**
     *  @brief Opens a project and encodes it contents to JSON format.
     *
     * @param info (Optional) A project path. If a project is loaded to memory, you can ommit this as it will be the default project to load.
     * @return (JS String) A JSON string.
     * @author Nicolas Cabrera Lettiere
     */
    Napi::Value ReadProjectContents(const Napi::CallbackInfo &info);

    /**
     *  @brief Updates a desired project with new data.
     *
     * @param info  A dictionary containing Name and Description. (Path entry will be ignored. You should use MoveProject() method);
     * @return (JS Boolean) If all updates were successful, returns true.
     * @author Nicolas Cabrera Lettiere
     */
    Napi::Value UpdateProject(const Napi::CallbackInfo &info);
} // namespace rus
#endif
