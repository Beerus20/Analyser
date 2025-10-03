#!/bin/bash

FILES=$(find . -type f -name "*.test.cpp" | sort)
HEADERS=$(echo $FILES | tr ' ' '\n' | awk '{printf "#include \"%s\"\n", $1}')

for file in $FILES; do
	FUNCTIONS=$(ctags -x --c++-kinds=f $file | sort -n -k3 | awk '{printf "\t%s();\n",$1}')
	echo -e "[\033[32m$file\033[0m]"
	echo "
	$HEADERS

	int	main(void)
	{
	$FUNCTIONS
		return (0);
	}
	" > main.cpp

	c++ main.cpp -o test && $1 ./test
	rm -rf main.cpp test
done