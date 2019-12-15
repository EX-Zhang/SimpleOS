#!Makefile

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name "*.s")
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

CC = gcc
LD = ld
ASM = nasm

C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T scripts/kernel.ld -m elf_i386 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

all: $(S_OBJECTS) $(C_OBJECTS) link

.c.o:
	$(CC) $(C_FLAGS) $< -o $@

.s.o:
	$(ASM) $(ASM_FLAGS) -o $@ $<

link:
	$(LD) $(S_OBJECTS) $(C_OBJECTS) $(LD_FLAGS) -o kernel/kEntry 


.PHONY:clean
clean:
	$(RM) $(S_OBJECTS) $(C_OBJECTS)
