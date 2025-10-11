#include <iostream>
#include <vector>
#include "includes/Analyser.hpp"
#include "src/Converter/Converter.hpp"

int	main(int, char **argv)
{
	std::cout << "Analyser initialisation" << std::endl;
	SystemTree	tree;

	tree.load(argv[1],1);
	std::cout << tree << std::endl;
	Converter::headerFile(argv[1]);
	std::cout << "\n\nDATA CONVERTER : \n" << Converter::_data.dump(4) << std::endl;
	//Text	text(argv[1]);
	
	//text.addSeparators("L");
	//while (!text.eof())
	//{
	//	std::cout << text.getWord() << std::endl;
	//	std::cout << text << std::endl;
	//}
	return (0);
}
