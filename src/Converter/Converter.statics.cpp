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
	{"type", ""},
	{"name", ""},
	{"id", -1},
	{"level", 0},
	{"begin", false},
	{"has_inheritance", false},
	{"found_object_keyword", false},
	{"container_has_inited", false},
	{"container_name_getted", false}
};