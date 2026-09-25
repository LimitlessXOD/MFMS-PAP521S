CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c employees.c budget.c suppliers.c assets.c reports.c
OBJ = $(SRC:.c=.o)
TARGET = mfms

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
