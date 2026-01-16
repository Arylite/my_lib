# Compiler and tools
CC := epiclang
AR := ar rcs
RM := rm -rf
MKDIR := mkdir -p
INSTALL := install

# Project information
VERSION := 1.5.0
SONAME := libmy.so.$(shell echo $(VERSION) | cut -d. -f1)
LIB_NAME := libmy

# Directories
SRC_DIR := src
BUILD_DIR := build
DIST_DIR := dist
INCLUDE_DIR := include
INSTALL_DIR ?= /usr/local
TEST_DIR := tests

# Flags
CFLAGS += -Wall -Wextra -Werror -I$(INCLUDE_DIR) -fPIC
OPTFLAGS ?= -O2
LDFLAGS += -shared
TEST_CFLAGS := -I$(INCLUDE_DIR) -I$(SRC_DIR) -I$(BUILD_DIR) -Wall -Wextra -Werror -fPIC -lcriterion

# Build type
DEBUG ?= 0
ifeq ($(DEBUG),1)
    CFLAGS += -g -DDEBUG
    OPTFLAGS = -O0
endif
CFLAGS += $(OPTFLAGS)

# NO_MALLOC flag to exclude malloc-dependent files
NO_MALLOC ?= 0
ifeq ($(NO_MALLOC),1)
    CFLAGS += -DNO_MALLOC
endif

# Sources and objects (recursively find all .c files under $(SRC_DIR))
# Use find so we pick up sources in subdirectories like src/io, src/math, src/string
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')
# Exclude malloc-dependent files if NO_MALLOC is set
ifeq ($(NO_MALLOC),1)
    SRCS := $(filter-out $(SRC_DIR)/string/strdup.c $(SRC_DIR)/string/str_to_word_array.c,$(SRCS))
endif
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Test sources
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)

# Outputs
STATIC_LIB := $(LIB_NAME).a
SHARED_LIB := $(LIB_NAME).so.$(VERSION)
SHARED_LINK := $(LIB_NAME).so

# Colors
BLUE := \033[0;34m
GREEN := \033[0;32m
RED := \033[0;31m
RESET := \033[0m

# Verbose mode
V ?= 0
ifeq ($(V),1)
    Q :=
    VECHO = @true
else
    Q := @
    VECHO = @printf "$(BLUE)%s$(RESET) %s\n"
endif

# Default target
all: static shared

# Build object files with automatic header dependencies
# Ensure destination directory for the object exists (handles nested dirs)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(VECHO) "CC" $<
	$(Q)$(MKDIR) $(dir $@)
	$(Q)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Static library
static: $(BUILD_DIR)/$(STATIC_LIB)

$(BUILD_DIR)/$(STATIC_LIB): $(OBJS) | $(DIST_DIR)
	$(VECHO) "AR" $@
	$(Q)$(AR) $@ $(OBJS)
	$(Q)cp -f $@ $(DIST_DIR)/$(STATIC_LIB)
	$(VECHO) "CP" $(DIST_DIR)/$(STATIC_LIB)

# Shared library
shared: $(BUILD_DIR)/$(SHARED_LIB)

$(BUILD_DIR)/$(SHARED_LIB): $(OBJS) | $(DIST_DIR)
	$(VECHO) "LD" $@
	$(Q)$(CC) $(LDFLAGS) -o $@ $(OBJS)
	$(Q)cp -f $@ $(DIST_DIR)/$(SHARED_LIB)
	$(Q)ln -sf $(SHARED_LIB) $(DIST_DIR)/$(SHARED_LINK)
	$(VECHO) "CP" $(DIST_DIR)/$(SHARED_LIB)
	$(VECHO) "LN" $(DIST_DIR)/$(SHARED_LINK)

# Create build directory
$(BUILD_DIR):
	$(VECHO) "MKDIR" $@
	$(Q)$(MKDIR) $(BUILD_DIR)

# Create dist directory for final artifacts
$(DIST_DIR):
	$(VECHO) "MKDIR" $@
	$(Q)$(MKDIR) $(DIST_DIR)

# Clean up
clean:
	$(VECHO) "CLEAN" "build artifacts"
	$(Q)$(RM) $(BUILD_DIR)

fclean: clean
	$(VECHO) "CLEAN" "libraries"
	$(Q)$(RM) $(DIST_DIR) $(STATIC_LIB) $(SHARED_LIB) $(SHARED_LINK)

re: fclean all

# Test target
test: all
	$(VECHO) "TEST" "running tests"
	$(Q)$(CC) $(TEST_CFLAGS) $(TEST_SRCS) -L$(DIST_DIR) -lmy -o $(TEST_DIR)/test_my
	$(Q)LD_LIBRARY_PATH=$(DIST_DIR) ./$(TEST_DIR)/test_my
	$(Q)rm -f $(TEST_DIR)/test_my

# Debug build
debug:
	$(MAKE) DEBUG=1

# Install library
install: all
	$(VECHO) "INSTALL" "headers and libraries"
	$(Q)$(INSTALL) -d $(INSTALL_DIR)/include $(INSTALL_DIR)/lib
	$(Q)$(INSTALL) -m 644 $(INCLUDE_DIR)/*.h $(INSTALL_DIR)/include/
	$(Q)$(INSTALL) -m 644 $(DIST_DIR)/$(STATIC_LIB) $(INSTALL_DIR)/lib/
	$(Q)$(INSTALL) -m 755 $(DIST_DIR)/$(SHARED_LIB) $(INSTALL_DIR)/lib/
	$(Q)ln -sf $(SHARED_LIB) $(INSTALL_DIR)/lib/$(SHARED_LINK)

# Help
help:
	@echo "Available targets:"
	@echo "  all     : Build both static and shared libraries (default)"
	@echo "  static  : Build static library only"
	@echo "  shared  : Build shared library only"
	@echo "  test    : Build and run tests"
	@echo "  clean   : Remove build directory"
	@echo "  fclean  : Remove build directory and output files"
	@echo "  re      : Rebuild everything"
	@echo "  debug   : Build with debug symbols"
	@echo "  install : Install library to $(INSTALL_DIR)"
	@echo ""
	@echo "Configuration variables:"
	@echo "  V=1            : Verbose output"
	@echo "  DEBUG=1        : Build with debug flags"
	@echo "  NO_MALLOC=1    : Exclude malloc-dependent functions (strdup, str_to_word_array)"
	@echo "  CC=gcc         : Use different compiler"
	@echo "  OPTFLAGS       : Set optimization flags (default: -O2)"

# Include dependency files
-include $(OBJS:.o=.d)

.PHONY: all static shared clean fclean re debug install help test