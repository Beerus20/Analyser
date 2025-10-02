include files.mk

NAME			= analyser
CXXVERSION		= 98
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++$(CXXVERSION) -g
MAKEFLAGS 		+= --no-print-directory
ARGS			=

VALGRINDFLAGS	= --quiet
SVALGRINDFLAGS	= --leak-check=full --show-leak-kinds=all

ifneq ("$(ARG)","")
	ARGS := "$(ARG)"
endif

all				: $(NAME)

$(NAME)			: $(MAIN_OBJS)
					@$(call create_executable, $^, $@)

clean			:
					@rm -rf $(MAIN_OBJS)

fclean			: clean
					@$(MAKE) fclean -C ./cppUnit52
					@rm -rf $(NAME)

re				: fclean all


.PHONY			: all clean fclean re

include rules.mk
include functions.mk