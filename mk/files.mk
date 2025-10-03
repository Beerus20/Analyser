DIRECTORIES					= \
								Tester							\
								Color							\
								Log

DIR_LOG						= Log.cpp
DIR_TESTER					= Tester.cpp

FILES_TO_TEST				= $(shell find . -type f -name "*.test.cpp")

FILES						= \
								$(foreach dir, $(DIRECTORIES), \
									$(addprefix $(dir)/, $(DIR_$(shell echo $(dir) | tr a-z A-Z))) \
								)

OBJS						= \
								$(foreach dir, $(DIRECTORIES), \
									$(addprefix output/, $(DIR_$(shell echo $(dir) | tr a-z A-Z):%.cpp=%.o) )\
								) \
