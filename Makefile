CC = gcc

CFLAGS = -Wall -Werror -Wextra -std=gnu11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

all: s21_matrix.a

s21_matrix.a: 
	@$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o
	@ar rcs s21_matrix.a s21_matrix.o
	@rm -rf *.o

test:
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) s21_matrix_test.c s21_matrix.a -o test_exec
	./test_exec

clean:
	@rm -rf *.o
	@rm -rf s21_matrix.a
	@rm -rf test_exec

rebuild: clean all