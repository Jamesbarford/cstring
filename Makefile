OUT    := build
TARGET := tests.out
CC     := cc
CFLAGS := -Wall -Wextra -Wpedantic -g -O0

$(OUT)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(TARGET)

clean:
	rm $(TARGET)
	rm $(OUT)/*.o

OBJS = $(OUT)/main.o \
       $(OUT)/cstring.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

$(OUT)/main.o: \
	./main.c \
	./cstring.h

$(OUT)/cstring.o: \
	./cstring.c \
	./cstring.h
