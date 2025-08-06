CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = engine
SRCS = engine.c init.c  bitboards.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
