#ifndef __CONVERTER_HPP__
# define __CONVERTER_HPP__

# include <iostream>
# include "../../includes/dependencies.hpp"

class Converter
{  
	private:
		static Text						_text;
		static std::size_t				_level;
		static const Vector::string		_object_keywords;
		

		Converter(void);
		Converter(const Converter &other);
		Converter	&operator=(const Converter &other);

	public:
		static json						_data;

		virtual ~Converter(void);

		static void	headerFile(const std::string &path);
		static void	lineToJson(const std::string &line, void *);
		
		static void	showLine(const std::string &line);
		static void	isVariable(const std::string &line);
		static void	isFunction(const std::string &line);

		static void	addContainer(std::string &identifier, json *container);
		static void	initContainer(std::string &identifier, json *container);
		static void	addInfo(std::string &identifier, json *container);

};

#endif
