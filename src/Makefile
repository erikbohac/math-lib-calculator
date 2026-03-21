CXX = g+++
CXXFLAGS = -Wall -Wextra -pedantic --std=c++23 -I .
LDLIBS = -lm

EXECS = math-lib

MATH_SRCS = $(wildcard ./core/*.cpp)
MATH_OBJS = $(MATH_SRCS:.cpp=.o)

TEST_SRCS = $(wildcard ./test/*.cpp)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

.PHONY = all clean test #pack doc run stddev help

all: $(EXECS)

math-lib: $(MATH_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#pack:


clean:
	rm -f $(MATH_OBJS) $(TEST_OBJS) $(EXECS) run_tests


test: $(MATH_OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o run_tests $^ -lgtest -lgtest_main -pthread
	./run_tests


#doc:


#run:


#stddev:


#help:
