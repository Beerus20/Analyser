#include "Converter.hpp"

Text							Converter::_text;
std::size_t						Converter::_level(0);
const std::vector<std::string>	Converter::_keywords = {
	"class",
	"struct",
	"enum",
	"typedef"
};