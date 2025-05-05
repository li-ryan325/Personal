# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source files
SRC = main.cc chinese.cc
# Object files corresponding to the source files
OBJ = $(SRC:.cc=.o)
# The final executable
TARGET = chinese
# Header files
HEADER = chinese.h

# Default target (all)
all: $(TARGET)

# Rule to build the target (executable)
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to build object files from source files
%.o: %.cc $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object and executable files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (do not conflict with filenames)
.PHONY: all clean
