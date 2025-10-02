#include <iostream>
#include <vector>
#include "Components/Components.hpp"

int	main(int, char **argv)
{
	std::cout << "Analyser initialisation" << std::endl;
	SystemTree	tree;

	tree.load(argv[1], -1);
	std::cout << tree.getPaths().dump(2) << std::endl;
	std::cout << tree.getNames().dump(2) << std::endl;
	return (0);
}
