##
## EPITECH PROJECT, 2026
## MyLib
## File description:
## Modern, standalone Makefile for a C library
##

# --- Project Configuration ---
NAME        := my
VERSION     := 2.0.0
# Portable version parsing without external 'cut'
MAJOR       := $(firstword $(subst ., ,$(VERSION)))

# --- Directories ---
SRC_DIR     := src
INC_DIR     := include
BUILD_DIR   := build
DIST_DIR    := dist
TEST_DIR    := tests

# --- Compilation Settings ---
CC          ?= gcc
AR          := ar rcs
RM          := rm -rf
MKDIR       := mkdir -p
INSTALL     := install

# --- Flags ---
# Using override to ensure mandatory flags are kept if user passes CFLAGS
override CFLAGS += -Wall -Wextra -Werror -I$(INC_DIR) -fPIC
OPTFLAGS    ?= -O2
LDFLAGS     := -shared -Wl,-soname,lib$(NAME).so.$(MAJOR)

# Build Modes
DEBUG       ?= 0
ifeq ($(DEBUG),1)
    override CFLAGS += -g3 -DDEBUG
    OPTFLAGS := -O0
endif
override CFLAGS += $(OPTFLAGS)

# NO_MALLOC support
NO_MALLOC   ?= 0
ifeq ($(NO_MALLOC),1)
    override CFLAGS += -DNO_MALLOC
endif

# --- Source Management ---
empty :=
space := $(empty) $(empty)

# Explicit submodule list for portability and speed
SUBDIRS     := array gc io math memory string string/printf

# Pure GNU Make source discovery (no 'find' command)
SRCS        := $(wildcard $(SRC_DIR)/*.c) \
               $(foreach dir,$(SUBDIRS),$(wildcard $(SRC_DIR)/$(dir)/*.c))

# Auto-detect malloc-dependent files and their dependents if NO_MALLOC is set
ifeq ($(NO_MALLOC),1)
    # 1. Start with files that directly use malloc
    MALLOC_SRCS := $(shell grep -l "malloc" $(SRCS) 2>/dev/null)
    SRCS        := $(filter-out $(MALLOC_SRCS),$(SRCS))
    
    # 2. Extract symbols (filenames) that were removed
    BAD_SYMS    := $(patsubst $(SRC_DIR)/%.c,%,$(MALLOC_SRCS))
    BAD_SYMS    := $(notdir $(BAD_SYMS))
    
    # 3. Pass 1: Remove files that use these symbols
    # Use grep to find occurrences as words
    DEP_PATTERN := $(subst $(space),|,$(BAD_SYMS))
    ifneq ($(DEP_PATTERN),)
        DEP_SRCS := $(shell grep -lE "\<($(DEP_PATTERN))\>" $(SRCS) 2>/dev/null)
        SRCS     := $(filter-out $(DEP_SRCS),$(SRCS))
        # Update symbols with newly removed files
        BAD_SYMS += $(notdir $(patsubst $(SRC_DIR)/%.c,%,$(DEP_SRCS)))
    endif

    # 4. Pass 2: Recurse one more level
    DEP_PATTERN := $(subst $(space),|,$(BAD_SYMS))
    ifneq ($(DEP_PATTERN),)
        DEP_SRCS_2 := $(shell grep -lE "\<($(DEP_PATTERN))\>" $(SRCS) 2>/dev/null)
        SRCS       := $(filter-out $(DEP_SRCS_2),$(SRCS))
    endif
endif

OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

# --- Output Artifacts ---
STATIC_LIB  := $(DIST_DIR)/lib$(NAME).a
SHARED_LIB  := $(DIST_DIR)/lib$(NAME).so.$(VERSION)
SONAME_LIB  := $(DIST_DIR)/lib$(NAME).so.$(MAJOR)
LINK_LIB    := $(DIST_DIR)/lib$(NAME).so

# --- Aesthetics ---
# Use bold variants for headers
BOLD        := \033[1m
BLUE        := \033[1;34m
CYAN        := \033[1;36m
GREEN       := \033[1;32m
RED         := \033[1;31m
YELLOW      := \033[1;33m
MAGENTA     := \033[1;35m
WHITE       := \033[1;37m
RESET       := \033[0m

# Verbosity Control
V           ?= 0
ifeq ($(V),1)
    Q       :=
    VECHO   := @true
else
    Q       := @
    # Modern prefix-based display
    VECHO   := @printf "$(BOLD)$(CYAN)%-10s$(RESET) %s\n"
endif

# --- Primary Targets ---
all: banner static

banner:
	@printf "$(BOLD)$(MAGENTA)--- Building MyLib v$(VERSION) ---$(RESET)\n"
	@printf "$(CYAN)Mode:$(RESET) %s | $(CYAN)Malloc:$(RESET) %s | $(CYAN)Sources:$(RESET) %s\n" \
		"$(if $(filter 1,$(DEBUG)),Debug,Release)" \
		"$(if $(filter 1,$(NO_MALLOC)),Disabled,Enabled)" \
		"$(words $(SRCS))"
	@printf "$(MAGENTA)----------------------------------$(RESET)\n"

static: $(STATIC_LIB)
	@printf "$(BOLD)$(GREEN)➜$(RESET) $(BOLD)Static library created:$(RESET) $(YELLOW)$<$(RESET)\n"

shared: $(SHARED_LIB)
	@printf "$(BOLD)$(GREEN)➜$(RESET) $(BOLD)Shared library created:$(RESET) $(YELLOW)$<$(RESET)\n"

# --- Build Rules ---
$(STATIC_LIB): $(OBJS) | $(DIST_DIR)
	$(VECHO) "AR" "$@"
	$(Q)$(AR) $@ $(OBJS)

$(SHARED_LIB): $(OBJS) | $(DIST_DIR)
	$(VECHO) "LD" "$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $(OBJS)
	$(Q)ln -sf $(notdir $(SHARED_LIB)) $(SONAME_LIB)
	$(Q)ln -sf $(notdir $(SHARED_LIB)) $(LINK_LIB)

# Object files with auto-dependency generation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(Q)$(MKDIR) $(dir $@)
	$(VECHO) "CC" "$<"
	$(Q)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# --- Directory Creation ---
$(BUILD_DIR) $(DIST_DIR):
	$(Q)$(MKDIR) $@

# --- Cleaning ---
clean:
	$(VECHO) "CLEAN" "Removing objects and dependencies..."
	$(Q)$(RM) $(BUILD_DIR)

fclean: clean
	$(VECHO) "CLEAN" "Removing libraries and distribution..."
	$(Q)$(RM) $(DIST_DIR)

re: fclean all

# --- Unit Tests ---
TEST_NAME := unit_tests
tests_run: all
	$(VECHO) "LD" "$(TEST_NAME)"
	$(Q)$(CC) -o $(TEST_NAME) $(wildcard $(TEST_DIR)/*.c) \
		-L$(DIST_DIR) -lmy -lcriterion -I$(INC_DIR) \
		-Wl,-rpath,$(abspath $(DIST_DIR))
	@printf "$(BOLD)$(MAGENTA)Running tests...$(RESET)\n"
	$(Q)./$(TEST_NAME)
	@printf "$(BOLD)$(GREEN)✔ All tests passed$(RESET)\n"

# --- Installation ---
PREFIX ?= /usr/local
install: all
	@printf "$(BOLD)$(CYAN)Installing to $(PREFIX)...$(RESET)\n"
	$(VECHO) "INSTALL" "headers"
	$(Q)$(INSTALL) -d $(PREFIX)/include
	$(Q)$(INSTALL) -m 644 $(INC_DIR)/*.h $(PREFIX)/include/
	$(VECHO) "INSTALL" "libraries"
	$(Q)$(INSTALL) -d $(PREFIX)/lib
	$(Q)$(INSTALL) -m 644 $(STATIC_LIB) $(PREFIX)/lib/
	$(Q)$(INSTALL) -m 755 $(SHARED_LIB) $(PREFIX)/lib/
	$(Q)ln -sf lib$(NAME).so.$(VERSION) $(PREFIX)/lib/lib$(NAME).so.$(MAJOR)
	$(Q)ln -sf lib$(NAME).so.$(VERSION) $(PREFIX)/lib/lib$(NAME).so
	@printf "$(BOLD)$(GREEN)✔ Installation complete$(RESET)\n"

# --- Help ---
help:
	@printf "$(BOLD)$(MAGENTA)MyLib Build System v$(VERSION)$(RESET)\n\n"
	@printf "$(BOLD)$(YELLOW)Usage:$(RESET) make [target] [variable=value]\n\n"
	@printf "$(BOLD)$(YELLOW)Targets:$(RESET)\n"
	@printf "  $(GREEN)all$(RESET)          Build static library (default)\n"
	@printf "  $(GREEN)static$(RESET)       Build lib$(NAME).a\n"
	@printf "  $(GREEN)shared$(RESET)       Build lib$(NAME).so\n"
	@printf "  $(GREEN)clean$(RESET)        Remove build artifacts\n"
	@printf "  $(GREEN)fclean$(RESET)       Remove artifacts and libraries\n"
	@printf "  $(GREEN)re$(RESET)           Full rebuild\n"
	@printf "  $(GREEN)tests_run$(RESET)    Compile and run unit tests\n"
	@printf "  $(GREEN)debug$(RESET)        Rebuild with -g3 -O0\n"
	@printf "  $(GREEN)install$(RESET)      Install to system (PREFIX=$(PREFIX))\n\n"
	@printf "$(BOLD)$(YELLOW)Configuration Variables:$(RESET)\n"
	@printf "  $(CYAN)V=1$(RESET)          Enable verbose output\n"
	@printf "  $(CYAN)DEBUG=1$(RESET)      Enable debug mode\n"
	@printf "  $(CYAN)NO_MALLOC=1$(RESET)  Auto-exclude malloc files\n"

debug:
	@$(MAKE) DEBUG=1 re --no-print-directory

# Automatic dependency inclusion
-include $(DEPS)

.PHONY: all static shared clean fclean re tests_run debug install help
