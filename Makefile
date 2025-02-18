##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for program compilation
##

.PHONY: all clean fclean re unit_tests tests_run

NAME = libasm.so

SRC	=

TEST_FILES =

OBJ = $(SRC:.asm=.o)

COMPILER = nasm

LINKER = ld

ASMFLAGS = -f elf64

LDFLAGS = -shared

all: $(NAME)

%.o: %.asm
	$(COMPILER) $(ASMFLAGS) -o $@ $<

$(NAME): $(OBJ)
	$(LINKER) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

unit_tests:

tests_run:
