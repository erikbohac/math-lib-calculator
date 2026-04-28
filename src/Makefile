CXX = g++
INCLUDE_DIR = .
CXXFLAGS = -Wall -Wextra -pedantic --std=c++23 -I$(INCLUDE_DIR)
GTESTFLAGS = -lgtest -lgtest_main -pthread
LDLIBS = -lm

BUILD_DIR = build

DOXY_OUT = $(BUILD_DIR)/docs
DOXYFILE = Doxyfile
DOXYFILE_GEN = $(DOXY_OUT)/$(DOXYFILE).gen

MATH_LIB_NAME = libmath.a
STDDEV_NAME = stddev
TEST_NAME = run_tests
CALC_NAME = Calc

MATH_LIB_DIR = core
STDDEV_DIR = profiling
TEST_DIR = test
CALC_DIR = calculator

#==========================================#
MATH_SRCS = $(wildcard $(MATH_LIB_DIR)/*.cpp)
MATH_OBJS = $(MATH_SRCS:%.cpp=$(BUILD_DIR)/%.o)

STDDEV_SRCS = $(wildcard $(STDDEV_DIR)/*.cpp)
STDDEV_OBJS = $(STDDEV_SRCS:%.cpp=$(BUILD_DIR)/%.o)

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.o)

CALC_SRCS = $(shell find $(CALC_DIR) -name "*.cpp")
CALC_OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(CALC_SRCS))

MATH_LIB := $(addprefix $(BUILD_DIR)/$(MATH_LIB_DIR)/, $(MATH_LIB_NAME))
STDDEV_EXE := $(addprefix $(BUILD_DIR)/$(STDDEV_DIR)/, $(STDDEV_NAME))
TEST_EXE := $(addprefix $(BUILD_DIR)/$(TEST_DIR)/, $(TEST_NAME))
CALC_BUILD_DIR := $(BUILD_DIR)/$(CALC_DIR)
MATH_LIB_ABS_PATH := $(abspath $(MATH_LIB))
INCLUDE_ABS_DIR := $(abspath $(INCLUDE_DIR))

.PHONY = all clean test stddev help doc calculator  #pack run


all: $(MATH_LIB) test stddev calculator


$(MATH_LIB): $(MATH_OBJS)
	rm -f $@
	ar rcs $@ $^


$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)


test: $(MATH_LIB) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(TEST_OBJS) $(MATH_LIB) $(GTESTFLAGS) $(LDLIBS)
	./$(TEST_EXE)


stddev: $(MATH_LIB) $(STDDEV_OBJS)
	$(CXX) $(CXXFLAGS) -o $(STDDEV_EXE) $(STDDEV_OBJS) $(MATH_LIB) $(LDLIBS)


help:
	echo "TODO"


$(DOXYFILE_GEN): $(DOXYFILE)
	mkdir -p $(DOXY_OUT)
	sed "s|@DOXY_OUT@|$(DOXY_OUT)|" $< > $@


doc: $(DOXYFILE_GEN)
	doxygen $(DOXYFILE_GEN)


calculator: $(MATH_LIB)
	cmake -S $(CALC_DIR) -B $(CALC_BUILD_DIR) \
		-DCALC_NAME=$(CALC_NAME) \
		-DMATH_LIB=$(MATH_LIB_ABS_PATH) \
		-DINCLUDE_DIR=$(INCLUDE_ABS_DIR)
	cmake --build $(CALC_BUILD_DIR)


#run


#pack

