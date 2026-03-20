CXX = g++ 
CXXFLAGS = -Wall -Wextra -pedantic --std=c++23 -I ../include
LDLIBS = -lm

EXECS = math-lib

MATH_SRCS = $(wildcard ./core/*.cpp)
MATH_OBJS = $(MATH_SRCS:.cpp=.o)

.PHONY = all #pack clean test doc run stddev help

all: $(EXECS)

math-lib: $(MATH_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#pack:


#clean:


#test:


#doc:


#run:


#stddev:


#help:



