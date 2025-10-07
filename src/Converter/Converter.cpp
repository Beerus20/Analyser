#include "Converter.hpp"
#include <vector>

std::size_t	Converter::level(0);

Converter::Converter(void) {}
Converter::Converter(const Converter &) {}
Converter::~Converter(void) {}
Converter	&Converter::operator=(const Converter &)
{
	return (*this);
}

void	Converter::headerFile(const std::string &path)
{
	(void)path;
	Utils::readLines(path, NULL, Converter::lineToJson);
}

void	Converter::showLine(const std::string &line)
{
	if (!line.empty())
		std::cout << line << std::endl;
}

void	Converter::lineToJson(const std::string &line, void *container)
{
	(void)line;
	(void)container;
	std::istringstream	ss(line);
	std::string			tmp;
	static int			nb(0);
	//bool				has_keyword(false);

	nb++;
	while (!ss.eof())
	{
		ss >> tmp;
		for (std::size_t i(0); i < Utils::keyword.size(); i++)
		{
			if (tmp == Utils::keyword[i])
			{
				std::cout << "[" << nb << "]" << std::endl;
				std::cout << "  " << Utils::trim(line) << std::endl;
				break ;
			}
		}
		//std::cout << "\t" << tmp << std::endl;
	}
	//std::cout << std::endl;
	//json	*values = reinterpret_cast<json *>(container);
}