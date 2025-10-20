#ifndef __CONVERTER_HPP__
# define __CONVERTER_HPP__

# include <iostream>
# include "../../includes/dependencies.hpp"

struct s_tmp
{
	std::string	type;
	std::string	name;
	bool		td;
	s_tmp(const std::string &type, const std::string &name, bool td) : type(type), name(name), td(td) {}
	bool	isEmpty(void) { return (type.empty() || name.empty());}
};

typedef struct s_tmp t_tmp;

class Converter {
	private:
		static Text						_text;
		static std::size_t				_level;
		static const Vector::string		_object_keywords;
		static t_tmp					_tmp;
		static Json						_info;

		Converter(void);
		Converter(const Converter &other);
		Converter	&operator=(const Converter &other);

	public:
		static Json						_data;

		virtual ~Converter(void);

		static void	headerFile(const std::string &path);
		static void	lineToJson(const std::string &line, void *);
		
		static void	showLine(const std::string &line);

		static void	getContainer(Json *container);
		static void	getInfo(void);
};

class Base 
{

};

class Test : public Base
{

};

#endif
