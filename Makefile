include mk/files.mk

NAME			= analyser
CXXVERSION		= 17
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
					@if [ -f $(NAME).a ]; then rm $(NAME).a; fi
					@rm -rf $(NAME)

re				: fclean all


.PHONY			: all clean fclean re

include mk/rules.mk
include mk/functions.mk