#include <iostream>
#include "includes/Analyser.hpp"

int	main(void)
{
	std::cout << "Analyser initialisation" << std::endl;
	json js;

	js["test"] = "test";
	js["number"] = 32;
	js["autre"] = json::parse(R"({"testes": "other"})");
	std::cout << js.dump(2) << std::endl;
	return (0);
}
