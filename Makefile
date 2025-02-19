##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for program compilation
##

.PHONY: all clean fclean re unit_tests tests_run

NAME = libasm.so

SRC	= src/strlen.asm

TEST_FILES = tests/tests_strlen.c

OBJ = $(SRC:.asm=.o)

TEST_OBJ = $(TEST_FILES:.c=.o)

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
	rm -f $(TEST_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gcno
	rm -f *.gcda

re: fclean all

unit_tests: $(OBJ) $(TEST_OBJ) $(NAME)
	gcc -o unit_tests $(OBJ) $(TEST_OBJ) \
	-L. -lasm -lcriterion --coverage

tests_run: unit_tests
	LD_LIBRARY_PATH=. ./unit_tests
