#include "Converter.hpp"
#include <vector>

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
	std::string			tmp;
	std::string			key("");

	Converter::_text.setContent(line);
	while (!Converter::_text.eof())
	{
		Converter::_text >> tmp;
		if (Utils::find(Converter::_keywords, tmp) != Converter::_keywords.end())
			key += (key.empty() ? "" : ",") + tmp;
		else
			break ;
		//std::cout << "\t" << tmp << std::endl;
	}
	//std::cout << std::endl;
	//json	*values = reinterpret_cast<json *>(container);
}

void	Converter::initInfo(std::string &identifier, json *container)
{
	if (container == NULL)
		return ;
	if (container->find("classes") == container->end())
		(*container)["classes"] = json::array();
	(*container)["classes"].push_back({
		{"type", identifier} ,
		{"name", ""} ,
		{"inheritance", json::array()} ,
		{"variables", json::array()} ,
		{"functions", json::array()}
	});
}

void	Converter::addInfo(std::string &identifier, json *container)
{
	if (container == NULL || container->find("classes") == container->end())
		return ;
	std::string	tmp("");

	while (Converter::_text.eof())
	{
		Converter::_text >> tmp;
		if (Utils::find(Converter::_keywords, tmp) != Converter::_keywords.end())
			break;
	}

	if (identifier.find('(') != std::string::npos && identifier.find(')') != std::string::npos)
	{
		(*container)["classes"].back()["functions"].push_back({
			{"name", identifier.substr(0, identifier.find('('))} ,
			{"returnType", ""} ,
			{"parameters", json::array()}
		});
	}
	else
	{
		(*container)["classes"].back()["variables"].push_back({
			{"name", identifier} ,
			{"type", ""} ,
			{"value", ""}
		});
	}
}