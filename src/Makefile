CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic --std=c++23 -I .
LDLIBS = -lm

BUILD_DIR = build
EXECS_NAME = stddev
MATH_LIB_NAME = libmath.a
TESTS_NAME = run_tests

MATH_DIR = core
STDDEV_DIR = profiling
TEST_DIR = test

MATH_LIB = $(patsubst %,$(BUILD_DIR)/%,$(MATH_LIB_NAME))
MATH_SRCS = $(wildcard $(MATH_DIR)/*.cpp)
MATH_OBJS = $(MATH_SRCS:%.cpp=$(BUILD_DIR)/%.o)

STDDEV_SRCS = $(wildcard $(STDDEV_DIR)/*.cpp)
STDDEV_OBJS = $(STDDEV_SRCS:%.cpp=$(BUILD_DIR)/%.o)

TEST_EXE = $(patsubst %,$(BUILD_DIR)/%,$(TESTS_NAME))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.o)

.PHONY = all clean test stddev help #pack doc run



all: $(MATH_LIB) $(EXECS_NAME)


$(MATH_LIB): $(MATH_OBJS)
	rm -f $@
	ar rcs $@ $^


$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)


test: $(MATH_LIB) $(TEST_OBJS)
	@mkdir -p $(dir $(TEST_EXE))
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(TEST_OBJS) -L$(BUILD_DIR) -lmath -lgtest -lgtest_main -pthread $(LDLIBS)
	./$(TEST_EXE)


stddev: $(MATH_LIB) $(STDDEV_OBJS)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $(STDDEV_OBJS) -L$(BUILD_DIR) -lmath $(LDLIBS)


help:
	echo "TODO"


#doc


#run


#pack

