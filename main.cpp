#include <iostream>
#include <vector>
#include "includes/Analyser.hpp"

int	main(int, char **argv)
{
	std::cout << "Analyser initialisation" << std::endl;
	SystemTree	tree;

	tree.load(argv[1],1);
	std::cout << tree << std::endl;

	return (0);
}
