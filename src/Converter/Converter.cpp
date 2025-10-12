#include "Converter.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

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
	Converter::_text.addSeparators("{};(),");
	Utils::readLines(path, &Converter::_data, Converter::lineToJson);
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
	std::string			key("");

	Converter::_text.setContent(line);
	if (Converter::_text.getContent().empty())
		return ;
	while (1)
	{
		Converter::_text >> Converter::_tmp.name;
		if (Converter::_text.hasFoundSeparator("{(;") || Converter::_text.eof())
			break ;
		else if (!Converter::_text.eof())
			Converter::_tmp.type += " " + Converter::_tmp.name;
	}
	std::cout
		<< "Type : " << Converter::_tmp.type << std::endl
		<< "Name : " << Converter::_tmp.name << std::endl << std::endl;
	Converter::_tmp = {"", ""};
}

void	Converter::initContainer(std::string &identifier, json *container)
{
	std::string	tmp("");

	if (container == NULL)
		return ;
	if (container->find("containers") == container->end())
		(*container)["containers"] = json::array();
	while (1)
	{
		Converter::_text >> tmp;
		if (Utils::find(Converter::_object_keywords, tmp) != Converter::_object_keywords.end())
			identifier += " " + tmp;
		else
			break ;
	}
	(*container)["containers"].push_back({
		{"type", identifier} ,
		{"name", tmp} ,
		{"inheritance", json::array()} ,
		{"variables", json::array()} ,
		{"functions", json::array()}
	});

	if (Converter::_text.hasFoundSeparator(":"))
	{
		
	}
	while (!Converter::_text.getFoundSeparators().empty())
	{

	}
}

void	Converter::addContainer(std::string &identifier, json *container)
{
	(void)identifier;
	(void)container;
	if (container == NULL || container->find("classes") == container->end())
		return ;
	
}

void	Converter::addInfo(std::string &identifier, json *container)
{
	if (container == NULL || container->find("classes") == container->end())
		return ;
	std::string	tmp("");

	while (Converter::_text.eof())
	{
		Converter::_text >> tmp;
		//if (Utils::find(Converter::_object_keywords, tmp) != Converter::_object_keywords.end())
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
