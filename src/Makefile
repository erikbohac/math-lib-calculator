CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic --std=c++23 -I .
LDLIBS = -lm

BUILD_DIR = build

EXECS = $(BUILD_DIR)/stddev
LIBS = $(BUILD_DIR)/libmath.a

MATH_DIR = core
STDDEV_DIR = stddev
TEST_DIR = test
TEST_EXE = $(BUILD_DIR)/$(TEST_DIR)/run_tests

MATH_SRCS = $(wildcard $(MATH_DIR)/*.cpp)
MATH_OBJS = $(MATH_SRCS:%.cpp=$(BUILD_DIR)/%.o)

STDDEV_SRCS = $(wildcard $(STDDEV_DIR)/*.cpp)
STDDEV_OBJS = $(STDDEV_SRCS:%.cpp=$(BUILD_DIR)/%.o)

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.o)

.PHONY = all clean test help #pack doc run



all: $(LIBS) $(EXECS)


$(LIBS): $(MATH_OBJS)
	rm -f $@
	ar rcs $@ $^


$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)


test: $(LIBS) $(TEST_OBJS)
	@mkdir -p $(dir $(TEST_EXE))
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(TEST_OBJS) -L$(BUILD_DIR) -lmath -lgtest -lgtest_main -pthread $(LDLIBS)
	./$(TEST_EXE)


$(BUILD_DIR)/stddev: $(LIBS) $(STDDEV_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(STDDEV_OBJS) -L$(BUILD_DIR) -lmath $(LDLIBS)


help:
	echo "TODO"


#doc


#run


#pack

