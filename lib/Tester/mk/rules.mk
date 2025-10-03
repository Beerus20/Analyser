output		:
				@if [ ! -d $@ ]; then mkdir $@; fi

output/%.o	: %.cpp | output
				@$(call create_object, $<, $@)

run			: $(NAME)
				./$(NAME) $(ARGS)

run\:./%	: $(OBJS)
				$(call runner,$(subst run:,,$@))

rerun		: re run
rerun\:./%	: re
				$(call runner,$(subst rerun:,,$@))

revrun		: re vrun
revrun\:./%	: re
				$(call runner,$(subst revrun:,,$@), valgrind $(VALGRINDFLAGS))

revsrun		: re vsrun
revsrun\:./%: re
				$(call runner,$(subst revsrun:,,$@), valgrind $(SVALGRINDFLAGS))

vrun		:
				./run.sh "valgrind $(SVALGRINDFLAGS)"

vrun\:./%	: $(OBJS)
				$(call runner, $(subst vrun:,,$@), valgrind $(VALGRINDFLAGS))

vsrun		: $(NAME)
				valgrind $(SVALGRINDFLAGS) ./$(NAME) $(ARGS)

vsrun\:./%	: $(OBJS)
				$(call runner,$(subst vsrun:,,$@), valgrind $(SVALGRINDFLAGS))

.PHONY		: run rerun revrun vrun vsrun test

echo		:
				@ctags -x --c++-kinds=f $(FILES_TO_TEST)
# ctags -x --c++-kinds=f func.cpp | awk '{print $6}' | awk -F '[()]' ' {print $3}'

init		:
				$(call create_main)