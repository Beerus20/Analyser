include mk/files.mk

NAME			= analyser
CXXVERSION		= 11
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
					@rm -rf $(NAME)

re				: fclean all


.PHONY			: all clean fclean re

include mk/rules.mk
include mk/functions.mk