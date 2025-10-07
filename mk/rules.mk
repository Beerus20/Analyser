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

vrun		: $($NAME)
				valgrind $(VALGRINDFLAGS) ./$(NAME) $(ARGS)

vrun\:./%	: $(OBJS)
				$(call runner, $(subst vrun:,,$@), valgrind $(VALGRINDFLAGS))

vsrun		: $(NAME)
				valgrind $(SVALGRINDFLAGS) ./$(NAME) $(ARGS)

vsrun\:./%	: $(OBJS)
				$(call runner,$(subst vsrun:,,$@), valgrind $(SVALGRINDFLAGS))

test		: $(NAME)
				$(call loop_run,$(TEST_FILES))
				$(call showNotTestedFiles,$(FILES_NOT_TESTED))

test\:%		: $(OBJS)
				$(call loop_run, $(filter ./.tests/$(subst test:,,$@)/%, $(TEST_FILES)))

commit		:
				@$(call create_commit)

commit\:%	: 
				@$(call create_commit,$(subst commit:,,$@))

push		: commit
				@git push

push\:%		:
				@$(call create_commit,$(subst push:,,$@))
				@git push

lib			: $(OBJS)
				ar rcs $(NAME).a $(OBJS)

create_dep_lib	:
					$(call make_loop_libs, lib)
