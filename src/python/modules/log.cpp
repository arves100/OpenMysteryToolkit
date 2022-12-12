/*
 * @file: python/modules/log.cpp
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <python/modules.h>

#include <ncine/common_macros.h>

static void logerr(std::string fmt)
{
	LOGE_X("%s", fmt.c_str());
}

static void logwarn(std::string fmt)
{
	LOGW_X("%s", fmt.c_str());
}

static void loginfo(std::string fmt)
{
	LOGI_X("%s", fmt.c_str());
}

static void logdebug(std::string fmt)
{
	LOGD_X("%s", fmt.c_str());
}

MOD_FUNC(log)
{
	m.def("error", logerr);
	m.def("info", loginfo);
	m.def("warn", logwarn);
	m.def("debug", logdebug);
}
