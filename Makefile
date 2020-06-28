CC = gcc
SOURCE_DIR = src/
INCLUDE_DIR = include/

CFLAGS=-c -Wall -I$(INCLUDE_DIR)

LDFLAGS =
SOURCES = $(wildcard $(SOURCE_DIR)*.c)
OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE = daemon

all: $(SOURCES) $(EXECUTABLE)

clean:
	-rm $(OBJECTS)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
