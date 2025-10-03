# CREATION ==========================================================
define create_object
	@$(CXX) $(CXXFLAGS) -c $(1) -o $(2)
endef

define create_executable
	$(CXX) $(CXXFLAGS) $(3) $(1) -o $(2) $(4)
endef

define runner
	@$(MAKE) lib -C cppUnit52
	@$(call create_executable, $(OBJS) $(1), $(NAME), -I./cppUnit52, -L./cppUnit52 -lcppUnit)
	$(2) ./$(NAME) $(ARGS)
	@rm -rf $(NAME)
endef

define loop_run
	@$(MAKE) lib -C cppUnit52
	@status=0;\
	for file in $(1); do \
		echo "\e[4;34m $$file :\e[0;m"; \
		if ! $(call create_executable, $(OBJS) $$file, $(NAME), -I./cppUnit52, -L./cppUnit52 -lcppUnit) ; then \
			exit 1; \
		fi; \
		if ! ./$(NAME) $(ARGS) ; then \
			status=1; \
		fi; \
	done;\
	exit $$status
endef

# CREATION OF RULES IF NOT CREATED ==========================================================
define create_rule
output/%.o: $(1)/%.cpp | output
	@$(call create_object, $$<, $$@)
endef

$(foreach dir, $(DIRECTORIES), $(eval $(call create_rule, $(dir))))
