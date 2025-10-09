#ifndef __CONVERTER_HPP__
# define __CONVERTER_HPP__

# include <iostream>
# include "../../includes/dependencies.hpp"

class Converter
{  
	private:
		static Text								_text;
		static std::size_t						_level;
		static const std::vector<std::string>	_keywords;

		Converter(void);
		Converter(const Converter &other);
		Converter	&operator=(const Converter &other);

	public:
		virtual ~Converter(void);

		static void	headerFile(const std::string &path);
		static void	lineToJson(const std::string &line, void *);
		
		static void	showLine(const std::string &line);
		static void	isVariable(const std::string &line);
		static void	isFunction(const std::string &line);

		static void	initInfo(std::string &identifier, json *container);
		static void	addInfo(std::string &identifier, json *container);
};

#endif