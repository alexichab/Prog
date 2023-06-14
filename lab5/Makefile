CC+FLAGS = gcc -Wall -MMD

all: main
-include *.d

main: main.o strings.o program.o
	$(CC+FLAGS) -o $@ $^

strings.o: strings.c
	$(CC+FLAGS) -c -o $@ $<

program.o: program.c
	$(CC+FLAGS) -c -o $@ $<

clean:
	rm -rf *.o *.d main