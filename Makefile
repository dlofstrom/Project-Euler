#Sample Makefile

OS := $(shell uname)
ifeq ($(OS),Darwin)
CC = clang
else
CC = gcc
endif

CFLAGS = -g -Wall -I./inc/
LIBS = -lcurl -ltidy -lm

#src folder contains common files
SOURCES = $(wildcard src/*.c)
OBJECTS = $(addprefix obj/,$(notdir $(SOURCES:.c=.o)))

#problem folder containg problem specific files
PROBLEMS = $(wildcard problems/*.c)
TARGETS = $(addprefix bin/,$(notdir $(PROBLEMS:.c=)))

all: $(TARGETS)
run-all: $(addprefix run-,$(notdir $(TARGETS)))

problem%: obj/problem%.o $(OBJECTS)
	$(CC) $(CFLAGS) $< $(OBJECTS) $(LIBS) -o bin/$@

run-problem%: bin/problem%
	@$<

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: obj/%.o
obj/%.o: problems/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bin/problem%: obj/problem%.o $(OBJECTS)
	$(CC) $(CFLAGS) $< $(OBJECTS) $(LIBS) -o $@

clean:
	@rm -f obj/* bin/*
