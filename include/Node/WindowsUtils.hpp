#include <napi.h>
#include <rus_config.hpp>

namespace rus
{
    /**
     * @brief (NAPI Method) Opens a native Windows dialogue to select a folder. (>=Windows Vista)
     * 
     * @param info (Optional) Either a JS buffer containing the parent window HWND or the PID Number of the window.
     * @return (JS String) returns either the selected dialogue path or an empty string.
     * @since (>=Windows Vista)
     * @author Nicolas Cabrera Lettiere
     */
    Napi::Value Win_SelFolder(const Napi::CallbackInfo &info);
    std::wstring GetProjectPath(const std::wstring &relative);

} // namespace rus