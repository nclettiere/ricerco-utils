#include <napi.h>
#include <rus_config.hpp>

#ifdef RUS_WIN
namespace rus
{
    /**
     * @brief (NAPI Method) Opens a native Windows dialogue to select a folder. (>=Windows Vista)
     * 
     * @param info This parameter should ONLY contain one argument and must be a JS buffer containg an HWND handle.
     * @return (JS String) returns either the selected dialogue path or an empty string.
     * @since (>=Windows Vista)
     * @author Nicolas Cabrera Lettiere
     */
    Napi::Value Win_SelFolder(const Napi::CallbackInfo &info);

} // namespace rus
#endif