#include "Converter.hpp"
#include <cctype>
#include <string>
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
	Converter::_data["test"] = Json::array();
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
	static Json	*data(reinterpret_cast<Json *>(container));

	(void)data;
	if (container == NULL)
		return ;
	Converter::_text.setContent(line);
	Converter::getInfo();
	//if (Converter::_info.at("begin") == false)
	//{
	//	Converter::getContainer(data);
	//}
	//else {
	
	//}
}

void	Converter::getInfo(void)
{
	std::string	tmp("");
	bool		active(false);

	while (!Converter::_text.eof())
	{
		Converter::_text >> tmp;
		//if (active == true)
		//{
		//	std::cout << "TMP VALUE : " << tmp << std::endl;
		//	std::cout << "Class : " << (Converter::_text.eof() ? "TRUE" : "FALSE") << std::endl;
		//	std::cout << "Cursor : " << Converter::_text.getCursor() << std::endl;
		//	std::cout << "Size : " << Converter::_text.getSize() << std::endl;
		//	active = false;
		//}
		if (tmp == "class")
		{
			active = true;
		}

		if (!Converter::_tmp.type.empty() && Converter::_text.testFoundSeparators(::isspace))
			Converter::_tmp.type += " ";
		if (!Converter::_text.testFoundSeparators(::isspace) || Converter::_text.eof())
		{
			if (active)
				std::cout << "TMP VALUE : " << tmp << std::endl;
			if (!tmp.empty())
				Converter::_tmp.name = tmp;
			break ;
		}
		if (Converter::_text.testFoundSeparators(::isspace))
		{
			if (!tmp.empty())
				Converter::_tmp.type += tmp;
		}
	}
	if (Converter::_tmp.type.find("class") != std::string::npos)
	{
		Converter::_text.showFoundSeparators();
		std::cout << "FOUND SEPARATOR OTHER : " << (!Converter::_text.testFoundSeparators(::isspace) ? "TRUE" : "FALSE") << std::endl;
	}
	if (!Converter::_text.testFoundSeparators(::isspace))
	{
		std::cout
			<< "type : [" << Converter::_tmp.type << "]" << std::endl
			<< "name : [" << Converter::_tmp.name << "]" << std::endl << std::endl;
		Converter::_tmp = {"", "", false};
	}
}

void	Converter::getContainer(Json *container)
{
	(void)container;
	//if (Utils::find(Converter::_object_keywords, Converter::_text.g))
}
