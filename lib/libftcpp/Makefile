# FILES
FILE			= \
					ft_format.cpp

# OBJECTS FILE
TEMPLATES		=

# OBJECTS PATH
TEMPLATES_PATH	= $(TEMPLATES:%.cpp=templates/%.cpp)

# OBJECTS
OBJS			= $(FILE:%.cpp=output/%.o)
TEMPLATES_OBJS	= $(TEMPLATES_PATH:templates/%.cpp=output/%.o)

# INCLUDES
INCLUDES		= -Iincludes

# VARIABLES
NAME			= libftcpp.a
CC				= g++ -g
AR				= ar rcs
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98

# MAKE FUNCTION
define compile
	$(CC) $(CPPFLAGS) $(INCLUDES) -c $(1) -o $(2)
endef

define exe
	$(CC) $(CPPFLAGS) $(INCLUDES) $(1) -o $(2)
endef

define create_lib
	$(AR) $(2) $(1)
endef

all			: $(NAME)

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.cpp | output
				$(call compile,$<,$@)

output/%.o	: Object/%.cpp | output
				$(call compile,$<,$@)

$(NAME)		: $(OBJS) $(TEMPLATES_OBJS)
				$(call exe,$^,$@)

clean		:
				rm -rf $(OBJ)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: all clean fclean re