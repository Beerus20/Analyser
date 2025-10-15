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
	Converter::_text.addTmpSeparators(":");
	Converter::_data = Json();
	Converter::_data["class"] = Json::array();
	Converter::_data["enum"] = Json::array();
	Converter::_data["struct"] = Json::array();
	Utils::readLines(path, &Converter::_data, Converter::lineToJson);
}

void	Converter::showLine(const std::string &line)
{
	std::cout << line << std::endl;
}

void	Converter::lineToJson(const std::string &line, void *container)
{
	(void)container;
	(void)line;

	Converter::_text.setContent(line);
	while (!Converter::_text.eof())
	{
		Converter::_text >> Converter::_tmp.name;
		if (Utils::find(Converter::_object_keywords, Converter::_tmp.name) != Converter::_object_keywords.end())
		{
			if (Converter::_tmp.name == "typedef")
			{
				Converter::_tmp.td = true;
				Converter::_text >> Converter::_tmp.name;;
			}
		}
	}

	//while (!Converter::_text.eof())
	//{
	//	Converter::_text >> Converter::_tmp.name;
	//	if (Converter::_text.hasFoundSeparator("}"))
	//		Converter::_info["level"] = static_cast<std::size_t>(Converter::_info.at("level")) - 1;				
	//	if (Converter::_text.hasFoundSeparator("{(;") || Converter::_text.eof())
	//	{
	//		if (Converter::_text.hasFoundSeparator("{"))
	//			Converter::_info["level"] = static_cast<std::size_t>(Converter::_info.at("level")) + 1;				

	//		if (!Converter::_tmp.type.empty() && !Converter::_tmp.name.empty())
	//			Converter::initData(reinterpret_cast<Json *>(container));
	//		break ;
	//	}
	//	else if (!Converter::_tmp.type.empty())
	//		Converter::_tmp.type += " ";
	//	Converter::_tmp.type += Converter::_tmp.name;
	//}
	//Converter::_tmp = {"", ""};
}

void	Converter::initData(Json *container)
{
	if (Utils::find(Converter::_object_keywords, Converter::_tmp.type) != Converter::_object_keywords.end())
	{
		(*container)[Converter::_tmp.type].push_back({
			{"name", Converter::_tmp.name},
			{"inheritances", Json::array()},
			{"variables", Json::array()},
			{"functions", Json::array()}
		});
		Converter::_info["name"] = Converter::_tmp.name;
		Converter::_info["type"] = Converter::_tmp.type;
	}
	if (!static_cast<std::size_t>(Converter::_info.at("level")))
		return ;
	if (Converter::_text.hasFoundSeparator("("))
	{
		Converter::addInfo("functions", container);
	}
	else
	{
		Converter::addInfo("variables", container);
	}
}

void	Converter::addInfo(const std::string &type, Json *container)
{
	Json	&tmp((*container)[Converter::_info["type"]]);

	for (std::size_t i(0); tmp.size(); i++)
	{
		if (tmp[i].at("name") == Converter::_info.at("name"))
		{
			tmp[i][type].push_back({
				{(type == "functions" ? "return type" : "type"), Converter::_tmp.type},
				{"name", Converter::_tmp.name}
			});
			break ;
		}
	}
}

void	Converter::initContainer(Json *container)
{
	if (container == NULL)
		return ;
	while (!Converter::_text.eof())
	{
		if (Utils::find(Converter::_object_keywords, Converter::_text.getWord()) != Converter::_object_keywords.end())
		{
			Converter::_info["found_object_keyword"] = true;
			break ;
		}	
	}
	if (!Converter::_info["found_object_keyword"])
		return ;
	Converter::_tmp.type = Converter::_text.getCurrentWord();
	//while ()
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
