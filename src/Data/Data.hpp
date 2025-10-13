#ifndef __DATA_HPP__
# define __DATA_HPP__

# include <iostream>
# include "../../includes/Analyser.hpp"

class Data
{
	private:
		Json	_content;

	public:
		Data(void);
		Data(const Data &other);
		virtual ~Data(void);
		Data		&operator=(const Data &other);
		Json		&operator[](const std::string &key);
		const Json	&operator[](const std::string &key) const;
		const Json	&getContent(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Data &to_show);

#endif