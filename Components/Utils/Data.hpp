#ifndef __DATA_HPP__
# define __DATA_HPP__

# include <iostream>
# include "../../includes/Analyser.hpp"
# include "Utils.hpp"

class Data
{
	private:
		json	_content;

	public:
		Data(void);
		Data(const Data &other);
		virtual ~Data(void);
		Data		&operator=(const Data &other);
		json		&operator[](const std::string &key);
		const json	&operator[](const std::string &key) const;
		const json	&getContent(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Data &to_show);

#endif