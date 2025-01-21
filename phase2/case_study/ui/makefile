# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and object files
SRCS = main.cpp admin_main.cpp ui_common.cpp patient_management.cpp
OBJS = $(SRCS:.cpp=.o)

# Output binary
TARGET = PatientManagementApp

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)