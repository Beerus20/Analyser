#include "Log.hpp"

void	Log::addFilter(const std::string &filter)
{
	Log::_apply_filter = true;
	Log::_filters.insert(filter);
}

void	Log::addFilter(Log::flags flag)
{
	Log::_apply_filter = true;
	if (flag == Log::ERROR)
		Log::_filters.insert(LABEL_ERROR);
	if (flag == Log::DEBUG)
		Log::_filters.insert(LABEL_DEBUG);
	if (flag == Log::INFO)
		Log::_filters.insert(LABEL_INFO);
	if (flag == Log::WARNING)
		Log::_filters.insert(LABEL_WARNING);
}


void	Log::rmFilter(const std::string &filter)
{
	Log::_filters.erase(filter);
	if (Log::_filters.size() == 0)
		Log::_apply_filter = false;
}

void	Log::rmFilter(Log::flags flag)
{

	if (flag == Log::ERROR)
		Log::_filters.erase(LABEL_ERROR);
	if (flag == Log::DEBUG)
		Log::_filters.erase(LABEL_DEBUG);
	if (flag == Log::INFO)
		Log::_filters.erase(LABEL_INFO);
	if (flag == Log::WARNING)
		Log::_filters.erase(LABEL_WARNING);
	if (Log::_filters.size() == 0)
		Log::_apply_filter = false;
}
