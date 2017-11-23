CC=c99
CFLAGS= -Wall -Wextra -pedantic -O0 -g -lm -Wno-unused-variable -Wno-unused-parameter
NASM=nasm
NASMFLAGS=-f elf64 -g -F DWARF

all: main 

main: uno_c.o uno_asm.o
	$(CC) $(CFLAGS) $^ -o $@

uno_asm.o: Uno.asm
	$(NASM) $(NASMFLAGS) $< -o $@

uno_c.o: Uno.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f main
