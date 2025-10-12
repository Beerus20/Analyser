#include "Converter.hpp"

Text					Converter::_text;
std::size_t				Converter::_level(0);
const Vector::string	Converter::_object_keywords = {
	"class",
	"struct",
	"enum",
	"typedef"
};
json					Converter::_data = json();
t_tmp					Converter::_tmp = {"", ""};
