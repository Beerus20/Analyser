#include "Converter.hpp"

Text					Converter::_text;
std::size_t				Converter::_level(0);
const Vector::string	Converter::_keywords = {
	"class",
	"struct",
	"enum",
	"typedef"
};
