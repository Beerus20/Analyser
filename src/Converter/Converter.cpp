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
	std::cout << line << std::endl;
}

void	Converter::lineToJson(const std::string &line, void *container)
{
	(void)container;
	std::string			key("");

	Converter::_text.setContent(line);
	while (!Converter::_text.eof())
	{
		Converter::_text >> Converter::_tmp.name;
		if (Converter::_text.hasFoundSeparator("{(;") || Converter::_text.eof())
		{
			std::cout
				<< "Type : [" << Converter::_tmp.type << "]" << std::endl
				<< "Name : " << Converter::_tmp.name << std::endl << std::endl;
			break ;
		}
		else if (!Converter::_tmp.type.empty())
			Converter::_tmp.type += " ";
		Converter::_tmp.type += Converter::_tmp.name;
	}
	Converter::_tmp = {"", ""};
}

void	Converter::initContainer(std::string &identifier, Json *container)
{
	std::string	tmp("");

	if (container == NULL)
		return ;
	if (container->find("containers") == container->end())
		(*container)["containers"] = Json::array();
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
		{"inheritance", Json::array()} ,
		{"variables", Json::array()} ,
		{"functions", Json::array()}
	});

	if (Converter::_text.hasFoundSeparator(":"))
	{
		
	}
	while (!Converter::_text.getFoundSeparators().empty())
	{

	}
}

//void	Converter::addInfo(std::string &identifier, json *container)
//{
//	if (container == NULL || container->find("classes") == container->end())
//		return ;
//	std::string	tmp("");

//	while (Converter::_text.eof())
//	{
//		Converter::_text >> tmp;
//		//if (Utils::find(Converter::_object_keywords, tmp) != Converter::_object_keywords.end())
//			break;
//	}

//	if (identifier.find('(') != std::string::npos && identifier.find(')') != std::string::npos)
//	{
//		(*container)["classes"].back()["functions"].push_back({
//			{"name", identifier.substr(0, identifier.find('('))} ,
//			{"returnType", ""} ,
//			{"parameters", Json::array()}
//		});
//	}
//	else
//	{
//		(*container)["classes"].back()["variables"].push_back({
//			{"name", identifier} ,
//			{"type", ""} ,
//			{"value", ""}
//		});
//	}
//}
