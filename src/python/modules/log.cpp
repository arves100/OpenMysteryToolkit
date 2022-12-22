/*
 * @file: python/modules/log.cpp
 * @author: Arves100
 * @date: 10/15/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#include <python/modules.h>

#include <ncine/common_macros.h>

/*!
* Prints an error log
* @param fmt String to print
*/
static void logerr(std::string fmt)
{
	LOGE_X("%s", fmt.c_str());
}

/*!
* Prints a warning log
* @param fmt String to print
*/
static void logwarn(std::string fmt)
{
	LOGW_X("%s", fmt.c_str());
}

/*!
* Prints an information log
* @param fmt String to print
*/
static void loginfo(std::string fmt)
{
	LOGI_X("%s", fmt.c_str());
}

/*!
* Prints a debug log
* @param fmt String to print
*/
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
