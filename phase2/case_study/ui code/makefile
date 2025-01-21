CC = g++
CFLAGS = -Wall -g
SRC = main.cpp ui_common.cpp patient_controller.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = PatientManagementApp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)