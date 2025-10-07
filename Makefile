include mk/files.mk
include mk/variables.mk

all				: $(NAME)

$(NAME)			: $(MAIN_OBJS) | create_dep_lib
					$(call create_executable, $^, $@, $(LIBS_INCLUDES), $(LIBS_FILES))

clean			:
					@rm -rf $(MAIN_OBJS)

fclean			: clean
					$(call make_loop_libs, fclean)
					@if [ -f $(NAME).a ]; then rm $(NAME).a; fi
					@rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re

include mk/rules.mk
include mk/functions.mk