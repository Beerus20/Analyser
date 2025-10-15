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
		Converter::_text.getWord();
		//if (Converter::_text.getCurrentWord().empty())
		//	continue ;
		if (Converter::_info.at("begin") == false)
		{
			if (!Converter::initContainer(reinterpret_cast<Json *>(container)))
				break ;
		}
		else
		{
			if (Converter::_text.hasFoundSeparator("}"))
			{
				Converter::_info["begin"] = false;
				Converter::_info["container_has_inited"] = false;
				Converter::_info["container_name_getted"] = false;
				Converter::_info["type"] = "";
			}
		}
	}
}

bool	Converter::initContainer(Json *container)
{
	if (container == NULL)
		return (false);
	if (Converter::_info.at("container_has_inited") == false)
	{
		if (Utils::find(Converter::_object_keywords, Converter::_text.getCurrentWord()) == Converter::_object_keywords.end())
			return (false);
		std::cout << "CONTAINER TYPE : " << Converter::_text.getCurrentWord() << std::endl;
		Converter::_info["id"] = 0;
		Converter::_info["type"] = Converter::_text.getCurrentWord();
		(*container)[Converter::_text.getCurrentWord()].push_back({
			{"name", ""},
			{"inheritances", Json::array()},
			{"variables", Json::array()},
			{"functions", Json::array()}
		});
		Converter::_info["container_has_inited"] = true;
		Converter::_text.setTmpSeparatorStatus(true);
		return (true);
	}
	if (Converter::_info.at("container_name_getted") == false)
	{
		//std::cout << "NAME CONTAINER : " << (*container)[Converter::_info["type"]][static_cast<int>(Converter::_info.at("id"))].dump(3) << std::endl;
		(*container)[Converter::_info["type"]][static_cast<int>(Converter::_info.at("id"))]["name"] = Converter::_text.getCurrentWord();
		Converter::_text.setTmpSeparatorStatus(false);
		Converter::_info["container_name_getted"] = true;
	}
	if (Converter::_text.hasFoundSeparator("{"))
		Converter::_info["begin"] = true;
	//if (Converter::_info.at("has_inheritance"))
	//{
	//	while ()
	//}
	return (true);
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
