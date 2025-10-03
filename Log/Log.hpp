#ifndef __LOG_HPP__
# define __LOG_HPP__

# include <vector>
# include <set>
# include <string>
# include <iostream>
# include "../Color/Color.hpp"

# define LABEL_ERROR	RED("[ ERROR ]")
# define LABEL_DEBUG	BLUE("[ DEBUG ]")
# define LABEL_INFO		GREEN("[ INFO ]")
# define LABEL_WARNING	YELLOW("[ WARNING ]")

class Log
{
	public:
		~Log(void);
		
		enum flags
		{
			ERROR,
			INFO,
			DEBUG,
			WARNING
		};

		static void	log(std::string const &message);
		static void	log(std::string const &label, std::string const &message);
		static void	sep(void);

		static void	info(std::string const &message);
		static void	debug(std::string const &message);
		static void	error(std::string const &message);
		static void	warning(std::string const &message);
		
		static void	addFilter(std::string const &filter);
		static void	addFilter(Log::flags);
		static void	rmFilter(std::string const &filter);
		static void	rmFilter(Log::flags);

		static void all(void);
		static void lock(void);
		static void unlock(void);


	private:
		static std::vector<std::string>	_contents;
		static std::set<std::string>	_filters;
		static bool						_is_locked;
		static bool						_apply_filter;
		Log(void);
		Log(Log const &);
		Log	&operator=(Log const &);

		static bool	checkOutput(std::string const &);
		static bool	filterExist(std::string const &);
};

#endif
