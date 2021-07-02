#include <rus_config.hpp>

#ifdef RUS_WIN
const std::string G_homeVar("USERPROFILE");
#else
const std::string G_homeVar("~");
#endif