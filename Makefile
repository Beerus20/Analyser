include mk/files.mk

NAME				= tester
CXX					= c++
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98 -g
MAKEFLAGS 			+= --no-print-directory
ARGS				=

VALGRINDFLAGS		= --quiet
SVALGRINDFLAGS		= --leak-check=full --show-leak-kinds=all

ifneq ("$(ARG)","")
	ARGS := "$(ARG)"
endif

all					: $(NAME)

$(NAME)				: $(OBJS)
						@$(call create_executable, $^, $@)

clean				:
						@rm -rf $(OBJS)

fclean				: clean
						@$(MAKE) fclean -C ./cppUnit52
						@rm -rf $(NAME)

re					: fclean all


.PHONY				: all clean fclean re

include mk/rules.mk
include mk/functions.mk
