#include "Converter.hpp"

Text					Converter::_text;
std::size_t				Converter::_level(0);
const Vector::string	Converter::_object_keywords = {
	"class",
	"struct",
	"enum",
	"typedef"
};
Json					Converter::_data = Json();
t_tmp					Converter::_tmp = {"", ""};
