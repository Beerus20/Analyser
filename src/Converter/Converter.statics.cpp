#include "Converter.hpp"

Text					Converter::_text;
std::size_t				Converter::_level(0);
const Vector::string	Converter::_object_keywords = {
	"class",
	"struct",
	"enum"
};
Json					Converter::_data = Json();
t_tmp					Converter::_tmp = {"", "", false};
Json					Converter::_info = {
	{"found_object", false},
	{"begin", false}
};
