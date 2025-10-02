DIRECTORIES					= \


FILES						= \
								$(foreach dir, $(DIRECTORIES), \
									$(addprefix $(dir)/, $(DIR_$(shell echo $(dir) | tr a-z A-Z))) \
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

