#include "Utils.hpp"

Utils::Utils(void) {}
Utils::Utils(const Utils &) {}
Utils::~Utils(void) {}
Utils	&Utils::operator=(const Utils &)
{
	return (*this);
}

void	Utils::removeAll(std::string &to_change, const std::string &str, std::size_t pos)
{
	std::size_t	len;

	if (pos >= to_change.length())
		return ;
	pos = to_change.find(str, pos);
	len = str.length();
	while (pos != std::string::npos)
	{
		to_change = to_change.erase((pos > 0 ? pos - 1 : pos), len);
		pos = to_change.find(str, pos);
	}
}

void	Utils::replaceAll(std::string &to_change, const std::string &word, const std::string &replace, std::size_t pos)
{
	std::size_t	len;

	if (pos >= to_change.length())
		return ;
	pos = to_change.find(word, pos);
	len = word.length();
	while (pos != std::string::npos)
	{
		to_change = to_change.replace(pos, len, replace);
		pos = to_change.find(word, pos);
	}
}

std::string Utils::getFileName(const std::string &path)
{
	std::string rvalue;

	for (int i((int) path.size() - 1); i >= 0; i--)
	{
		if (path[i] == '/')
			break;
		rvalue = path[i] + rvalue;
	}
	return (rvalue);
}
