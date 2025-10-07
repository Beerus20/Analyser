DIRECTORIES					= \
								Utils									\

DIR_UTILS					= \
								Data.cpp								\
								Utils.cpp

FILES						= \
								$(foreach dir, $(DIRECTORIES), \
									$(addprefix src/$(dir)/, $(DIR_$(shell echo $(dir) | tr a-z A-Z))) \
								)

OBJS						= \
								$(foreach dir, $(DIRECTORIES), \
									$(addprefix output/, $(DIR_$(shell echo $(dir) | tr a-z A-Z):%.cpp=%.o) )\
								) \

MAIN_OBJS					= $(OBJS) ./output/main.o

TO_TEST_FILES				= \
								$(foreach dir, $(DIRECTORIES), \
									$(addprefix ./.tests/$(dir)/, $(DIR_$(shell echo $(dir) | tr a-z A-Z):%.cpp=%.test.cpp)) \
								)

TEST_FILES					= \
								$(foreach file, $(TO_TEST_FILES), \
									$(shell if [ -e $(file) ]; then echo $(file); fi) \
								)

FILES_NOT_TESTED			= $(filter-out $(TEST_FILES), $(TO_TEST_FILES))


LIB_EMPLACEMENT				= ../
LIBS						= libftcpp
LIBS_EXT					= ftcpp
LIBS_PATH					= $(addprefix $(LIB_EMPLACEMENT),$(LIBS))

LIBS_INCLUDES				= \
								$(foreach i, $(shell seq 1 $(words $(LIBS))), \
									-I$(word $(i),$(LIBS_PATH))/includes)

LIBS_FILES					= \
								$(foreach i, $(shell seq 1 $(words $(LIBS))), \
									-L$(word $(i),$(LIBS_PATH)) \
									-l$(word $(i),$(LIBS_EXT)))

#echo :
#		echo $(LIBS_INCLUDES)
#		echo $(LIBS_FILES)