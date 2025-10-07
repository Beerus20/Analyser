NAME				= analyser
CXXVERSION			= 17
CXX					= c++
CXXFLAGS			= -Wall -Wextra -Werror -std=c++$(CXXVERSION) -g
MAKEFLAGS 			+= --no-print-directory
ARGS				=

VALGRINDFLAGS		= --quiet
SVALGRINDFLAGS		= --leak-check=full --show-leak-kinds=all

ifneq ("$(ARG)","")
	ARGS := "$(ARG)"
endif

NO_COMMIT_MESSAGE	= "No changes to commit."
Y					=
