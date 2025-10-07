TOTAL = $(words $(OBJS))

# CREATION ==========================================================
define make_loop_libs
	@$(foreach path, $(LIBS_PATH), \
		$(MAKE) $(1) -C $(path))
endef

define create_object
	@$(CXX) $(CXXFLAGS) -c $(1) -o $(2)
	@./mk/progress_bar.sh output $(TOTAL)
endef

define create_executable
	$(CXX) $(CXXFLAGS) $(3) $(1) -o $(2) $(4)
endef

define runner
	@$(call create_executable, \
		$(OBJS) $(1), \
		$(NAME), \
		$(LIBS_INCLUDES), \
		$(LIBS_FILES))
	$(2) ./$(NAME) $(ARGS)
	@rm -rf $(NAME)
endef

define loop_run
	@status=0;\
	for file in $(1); do \
		echo "\e[4;34m $$file :\e[0;m"; \
		if ! $(call create_executable, $(OBJS) $$file, $(NAME)) ; then \
			exit 1; \
		fi; \
		if ! ./$(NAME) $(ARGS) ; then \
			status=1; \
		fi; \
	done;\
	exit $$status
endef

define showNotTestedFiles
	$(eval length = $(shell echo $(FILES_NOT_TESTED) | tr ' ' '\n' | awk '{ print length, $$0 }' | sort -n | tail -n 1 | cut -d ' ' -f 1))
	@for file in $(1); do \
		printf "[ \e[31m%-$(length)s\e[0m ] : \e[30mNOT TESTED YET\e[0m\n" $$file; \
	done
endef

# CREATION OF RULES IF NOT CREATED ==========================================================
define create_rule
output/%.o: $(1)/%.cpp | output
	@$(call create_object, $$<, $$@)
endef

$(foreach dir, $(DIRECTORIES), $(eval $(call create_rule, src/$(dir))))


# GIT ==========================================================
define create_commit
	@if [ -n "$$(git status --porcelain)" ]; then \
		read -p "Do you want to commit changes? (y/n): " RESP; \
		if [ "$$RESP" = "y" ] || [ "$$RESP" = "Y" ]; then \
			git status; \
			if [ -z "$(1)" ]; then \
				read -p "Commit message : " COMMIT_MESSAGE; \
			else \
				COMMIT_MESSAGE="$(1)"; \
			fi; \
			if [ -z "$$COMMIT_MESSAGE" ]; then \
				COMMIT_MESSAGE="Auto-commit on $$(date)"; \
			fi; \
			git add .; \
			git status; \
			git commit -m "$$COMMIT_MESSAGE"; \
		fi \
	else \
		echo $(NO_COMMIT_MESSAGE); \
	fi
endef