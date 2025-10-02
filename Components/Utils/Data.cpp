#include "Data.hpp"

Data::Data(void) {}
Data::Data(const Data &other) : _content(other._content) {}
Data::~Data(void) {}
Data	&Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->_content = other._content;
	}
	return (*this);
}

json	&Data::operator[](const std::string &key)
{
	return (this->_content[key]);
}

const json	&Data::operator[](const std::string &key) const
{
	return (this->_content[key]);
}

const json	&Data::getContent(void) const
{
	return (this->_content);
}

std::ostream	&operator<<(std::ostream &os, const Data &to_show)
{
	os << to_show.getContent() << std::endl;
	return (os);
}
