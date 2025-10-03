#include "Log.hpp"
#include <vector>

std::vector<std::string>	Log::_contents;
std::set<std::string>		Log::_filters;
bool						Log::_is_locked(false);
bool						Log::_apply_filter(false);

Log::Log(void) {}
Log::Log(Log const &) {}
Log::~Log(void) {}

Log	&Log::operator=(Log const &)
{
	return (*this);
}

void	Log::log(std::string const &message)
{
	if (!Log::_is_locked)
	{
		if (Log::_apply_filter)
		{
			if (Log::checkOutput(message))
				std::cout << message << std::endl;
		}
		else
			std::cout << message << std::endl;
	}
	Log::_contents.push_back(message);
}

void	Log::log(const std::string &label, const std::string &message)
{
	Log::log("[ " + label + " ] : " + message);
}

void	Log::sep(void)
{
	bool	filter_status(Log::_apply_filter);
	
	Log::_apply_filter = false;
	Log::log(" ---------------------------------------------------------------- ");
	Log::_apply_filter = filter_status;
}

void	Log::info(std::string const &message)
{
	Log::log(LABEL_INFO" : " + message);
}

void	Log::debug(std::string const &message)
{
	Log::log(LABEL_DEBUG" : " + message);
}

void	Log::error(std::string const &message)
{
	Log::log(LABEL_ERROR" : " + message);
}

void	Log::warning(std::string const &message)
{
	Log::log(LABEL_WARNING" : " + message);
}

bool	Log::checkOutput(std::string const &message)
{
	for (std::set<std::string>::const_iterator filter(Log::_filters.begin()); filter != Log::_filters.end(); filter++)
	{
		if (message.find(*filter) != std::string::npos)
			return (true);
	}
	return (Log::_filters.empty());
}

void	Log::all(void)
{
	for (std::vector<std::string>::const_iterator content(Log::_contents.begin()); content != Log::_contents.end(); content++)
		std::cout << *content << std::endl;
}

void	Log::lock(void)
{
	Log::_is_locked = true;
}

void	Log::unlock(void)
{
	Log::_is_locked = false;
}
