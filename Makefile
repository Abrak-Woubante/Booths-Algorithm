CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

SRCS = boothMain.cpp fileInputOutputImp.cpp multiplicationImp.cpp 
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = booth_algorithm

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE) output_*

