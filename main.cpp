#include <iostream>
#include <vector>
#include "Components/Components.hpp"
#include "Components/SystemTree/SystemTree.hpp"

int	main(int, char **argv)
{
	std::cout << "Analyser initialisation" << std::endl;
	SystemTree	tree;

	tree.load(argv[1], SystemTree::tree, -1);
	std::cout << SystemTree::tree.dump(4) << std::endl;

	return (0);
}
