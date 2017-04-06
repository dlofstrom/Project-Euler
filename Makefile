#Sample Makefile

CC = clang

CFLAGS = -Wall -I./inc/
LIBS = -lcurl -ltidy

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
