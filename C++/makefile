AT := @
CC := gcc

TARGET_EXEC := main
SRC_DIRS := src
INC_DIRS := inc

CUR_DIR := $(shell pwd)
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)
OBJ_DIR := $(BUILD_DIR)/obj
BIN := $(BIN_DIR)/$(TARGET_EXEC)

comma := ,
empty :=
space := $(empty) $(empty)
newline := \n

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
CSOURCE := $(shell find $(SRC_DIRS) -name '*.c' )
CPPSOURCE := $(shell find $(SRC_DIRS) -name '*.cpp')

COBJS := $(CSOURCE:%.c=$(OBJ_DIR)/%.o)
CPPOBJS := $(CPPSOURCE:%.cpp=$(OBJ_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
# INC_DIRS += $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CFLAGS := -Wall
CXXFLAGS := -std=c++20
CPPFLAGS := $(INC_FLAGS)
LDFLAGS :=

all: $(BIN)

# Build step for C source
$(OBJ_DIR)/%.o: %.c
	$(AT) mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(OBJ_DIR)/%.o: %.cpp
	$(AT) mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# The final build step.
$(BIN): $(COBJS) $(CPPOBJS)
	$(AT) $(CXX) $^ -o $@ $(LDFLAGS)
	$(AT) echo "Done Building $@"

dump:
	$(AT) echo "C source \n$(subst $(space),$(newline),$(CSOURCE))\n"
	$(AT) echo "C objs \n$(subst $(space),$(newline),$(COBJS))\n"

.PHONY: clean dump
clean:
	$(AT)rm -r $(BUILD_DIR)
	$(AT)echo "Done $@"

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)

# $(foreach v, \
#     $(shell echo "$(filter-out .VARIABLES,$(.VARIABLES))" | tr ' ' '\n' | sort), \
#     $(info $(shell printf "%-20s" "$(v)")= $(value $(v))) \
# )