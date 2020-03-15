GOOGLE_TEST_LIB = gtest

BUILD_DIR ?= ./build
SRC_DIRS ?= ./code
TEST_DIRS ?= ./unit_tests

TARGET ?=  $(BUILD_DIR)/x
LIB ?=  $(BUILD_DIR)/libcode.a
DEBUG ?= 1
SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
TEST_SRCS := $(shell find $(TEST_DIRS) -name *.cpp)#
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
LIBS := $(LIB)  

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) 
ifeq ($(DEBUG), 1)
CPPFLAGS ?= $(INC_FLAGS) -g -Wall -MMD -MP --coverage
else
CPPFLAGS ?= $(INC_FLAGS) -O3 -Wall -DNDEBUG -MMD -MP 
endif
LINKFLAGS := -L$(BUILD_DIR)  -lcode -lgcov -l$(GOOGLE_TEST_LIB)

all: doxygen

$(TARGET): $(LIB) $(TEST_OBJS)
	$(CXX)  $(TEST_OBJS) $(LIB) $(LINKFLAGS)   -o $@

$(LIB): $(OBJS)
	ar $(LDFLAGS) rc $@ $(OBJS)
	ranlib $@


# c++ source
$(BUILD_DIR)/%.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean


coverage: unit_test
	lcov  --capture --directory $(BUILD_DIR)/$(SRC_DIRS)  --directory $(BUILD_DIR)/$(TEST_DIRS)  --output-file $(BUILD_DIR)/coverage.info
	lcov --remove $(BUILD_DIR)/coverage.info  '/usr/*' --output-file $(BUILD_DIR)/unit.tests
	genhtml --prefix /home/$(USER) $(BUILD_DIR)/unit.tests -t 'Unit test coverage' \
	--css-file doc/coverage.css \
	--html-epilog  doc/coverage_footer.html \
	--output-directory  $(BUILD_DIR)/html


doxygen: $(SRCS) coverage valgrind
	cd doc; doxygen

unit_test: target
	$(TARGET) -v

valgrind: target
	valgrind $(TARGET) -v >& $(BUILD_DIR)/latex/valgrind.tex

target: $(TARGET)

obj:  $(OBJS)

lib: $(LIB)

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p

