#include <iostream>
#include <vector>
#include "includes/Analyser.hpp"
#include "src/Converter/Converter.hpp"

int	main(int, char **argv)
{
	std::cout << "Analyser initialisation" << std::endl;
	//SystemTree	tree;

	//tree.load(argv[1],1);
	//std::cout << tree << std::endl;
	Converter::headerFile(argv[1]);
	return (0);
}
