#include "filemanager.h"
#if defined(_WIN32)
#include <Windows.h>
#elif defined(__linux__)
#include <linux/limits.h>
#include <unistd.h>
#endif

namespace max
{
	inline std::string apppath()
	{
#if defined _WIN32
		char buffer[MAX_PATH];
		GetModuleFileNameA(NULL, buffer, MAX_PATH);
		std::string::size_type pos = std::string(buffer).find_last_of("\\/");
		return std::string(buffer).substr(0, pos);
#elif defined __linux__
		char result[PATH_MAX];
		ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
		std::string appPath = std::string(result, (count > 0) ? count : 0);
		std::size_t found = appPath.find_last_of("/\\");
		return appPath.substr(0, found);
#endif

		return ""; // unknown
	}

	inline std::string mappath()
	{
		return apppath() + "/pxg/map/";
	}

	inline std::string matpath()
	{
		return apppath() + "/pxg/materials/";
	}

	inline std::string scriptpath()
	{
		return apppath() + "/pxg/scripts/";
	}
}