# ==========================================
# COMPILER SETTINGS
# ==========================================
CXX := g++
CXXFLAGS := -std=c++11 -w -I. -MMD -MP

# Directories
BUILD_DIR := build
INCLUDE_DIR := .
TEST_DIR := Tests

# ==========================================
# SOURCE FILE MANAGEMENT
# ==========================================

# 1. Main entry point
MAIN_SRC := main.cpp

# 2. Optional Test file (only if it exists)
TEST_SRC := $(wildcard test.cpp)

# 3. Common Sources (all .cpp except main + test files)
ALL_ROOT_CPP := $(wildcard *.cpp)
EXCLUDED_SRCS := $(MAIN_SRC) test.cpp test_s.cpp test_h.cpp
COMMON_SRC := $(filter-out $(EXCLUDED_SRCS), $(ALL_ROOT_CPP))

# ==========================================
# OBJECT FILES
# ==========================================
COMMON_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(COMMON_SRC))
MAIN_OBJ   := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(MAIN_SRC))
TEST_OBJ   := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST_SRC))

# ==========================================
# BINARIES
# ==========================================
RUN_BIN := $(BUILD_DIR)/run.out
TEST_BIN := $(BUILD_DIR)/test.out

# Dependency files
DEPS := $(wildcard $(BUILD_DIR)/*.d)

# ==========================================
# DEFAULT TARGET
# ==========================================
all: run

# Ensure build dir exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ==========================================
# COMPILATION RULES
# ==========================================

# Compile root .cpp files
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@$(CXX) -c -I$(INCLUDE_DIR) $(CXXFLAGS) -MF $(patsubst %.o,%.d,$@) $< -o $@

# Compile test folder .cpp files (if used)
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	@$(CXX) -c -I$(INCLUDE_DIR) $(CXXFLAGS) -MF $(patsubst %.o,%.d,$@) $< -o $@

# ==========================================
# LINKING
# ==========================================

# Main program
$(RUN_BIN): $(MAIN_OBJ) $(COMMON_OBJ)
	$(CXX) $^ -o $@

# Test program (only builds if test.cpp exists)
$(TEST_BIN): $(TEST_OBJ) $(COMMON_OBJ)
	@if [ -n "$(TEST_SRC)" ]; then \
		$(CXX) $^ -o $@; \
	else \
		echo "No test.cpp found. Skipping test build."; \
	fi

# ==========================================
# RUN COMMANDS
# ==========================================

run: $(RUN_BIN)
	./$(RUN_BIN)

test: $(TEST_BIN)
	@if [ -f $(TEST_BIN) ]; then ./$(TEST_BIN); fi

# ==========================================
# CLEAN
# ==========================================
clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

.PHONY: run test clean all