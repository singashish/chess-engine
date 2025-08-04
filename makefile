CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = engine
SRCS = engine.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
