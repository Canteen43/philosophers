#### MAIN SETTINGS ####

# Compiler to be used
CC				:= cc

# Compiler flags
CFLAGS			:= -Wall -Werror -Wextra -O3 -pthread

# Libraries to be linked (if any)
LIBS			:=

# Include directories
INCLUDES		:= -Iinc/

# Target executable
TARGET			:= philo

# Source files directory
SRC_DIR			:= src/

# Source files
SRC_FILES		+= main.c
SRC_FILES		+= f_create_forks.c
SRC_FILES		+= f_create_philos.c
SRC_FILES		+= f_destroy_forks.c
SRC_FILES		+= f_eat.c
SRC_FILES		+= f_execute_philo.c
SRC_FILES		+= f_increase_meal_count.c
SRC_FILES		+= f_join_philos.c
SRC_FILES		+= f_monitor_death.c
SRC_FILES		+= f_print_state.c
SRC_FILES		+= f_read_args.c
SRC_FILES		+= f_release_forks.c
SRC_FILES		+= f_return_and_error.c
SRC_FILES		+= f_sleep.c
SRC_FILES		+= f_take_forks.c
SRC_FILES		+= f_termination_condition_met.c
SRC_FILES		+= f_think.c
SRC_FILES		+= f_time_diff_ms.c
SRC_FILES		+= f_philos_full.c
SRC_FILES		+= f_philo_died.c
SRC_FILES		+= f_strlen.c
SRC_FILES		+= f_strtoi.c



# Object files directory
OBJ_DIR			:= obj/

# Object files
OBJ_FILES		:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# Dependency files directory
DEP_DIR			:= dep/

# Dependency files
DEPENDS			:= $(patsubst %.o, $(DEP_DIR)%.d, $(OBJ_FILES))
-include $(DEPENDS)

#### SHELL COMMANDS ####

RM				:= /bin/rm -f
MKDIR			:= /bin/mkdir -p
TOUCH			:= /bin/touch

#### LOCAL LIBRARIES ####

#### DEBUG SETTINGS ####

ifeq ($(DEBUG), 1)
	CFLAGS := $(filter-out -O3, $(CFLAGS))
	CFLAGS		+= -g3 -O0
endif

ifeq ($(DEBUG), 2)
	CFLAGS := $(filter-out -O3, $(CFLAGS))
	CFLAGS		+= -g3 -O0 -fsanitize=thread
endif

ifeq ($(DEBUG), 3)
	CFLAGS := $(filter-out -O3, $(CFLAGS))
	CFLAGS		+= -g3 -O0 -fsanitize=address
endif

#### TARGET COMPILATION ####

.DEFAULT_GOAL	:= all

all: $(TARGET) ## Build this project

# Compilation rule for object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(@D)
	@echo -n "[build] "
	$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

# Rule for linking the target executable
$(TARGET): $(OBJ_FILES)
	@echo -n "\n[link] "
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) $(INCLUDES) $(LIBS)
	-@echo -n "🚀 $(MAGENTA)" && ls -lah $(TARGET) && echo -n "$(RESET)"

#### LOCAL LIBS COMPILATION ####

#### ADDITIONAL RULES ####

clean: ## Clean objects and dependencies
	@echo -n "[clean] "
	$(RM) $(OBJ_FILES)
	@echo -n "[clean] "
	$(RM) -r $(OBJ_DIR)
	@echo -n "[clean] "
	$(RM) $(DEPENDS)
	@echo -n "[clean] "
	$(RM) -r $(DEP_DIR)

fclean: clean ## Restore project to initial state
	@echo -n "[fclean] "
	$(RM) $(TARGET)

re: fclean all ## Rebuild project

help: ## Show help info
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

.PHONY: all re clean fclean help

#### COLORS ####
# Color codes
RESET		:= \033[0m
BOLD		:= \033[1m
UNDERLINE	:= \033[4m

# Regular colors
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
MAGENTA		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m

# Background colors
BG_BLACK	:= \033[40m
BG_RED		:= \033[41m
BG_GREEN	:= \033[42m
BG_YELLOW	:= \033[43m
BG_BLUE		:= \033[44m
BG_MAGENTA	:= \033[45m
BG_CYAN		:= \033[46m
BG_WHITE	:= \033[47m

# This file was downloaded and adapted from: 
# https://github.com/tesla33io/philosophers/blob/main/philo/Makefile
# Thanks for the clean Makefile!