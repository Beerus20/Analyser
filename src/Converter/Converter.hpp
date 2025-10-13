#ifndef __CONVERTER_HPP__
# define __CONVERTER_HPP__

# include <iostream>
# include "../../includes/dependencies.hpp"

typedef struct s_tmp
{
	std::string	type;
	std::string	name;
	s_tmp(const std::string &type, const std::string &name) : type(type), name(name) {}
} t_tmp;

class Converter
{
	private:
		static Text						_text;
		static std::size_t				_level;
		static const Vector::string		_object_keywords;
		static t_tmp					_tmp;

		Converter(void);
		Converter(const Converter &other);
		Converter	&operator=(const Converter &other);

	public:
		static Json						_data;

		virtual ~Converter(void);

		static void	headerFile(const std::string &path);
		static void	lineToJson(const std::string &line, void *);
		
		static void	showLine(const std::string &line);
		static void	isVariable(const std::string &line);
		static void	isFunction(const std::string &line);

		static void	initData(Json &container);
		static void	initContainer(std::string &identifier, Json *container);

};

#endif
