CC = gcc -std=c11
CFLAG = -Wall -Werror -Wextra -D_GNU_SOURCE

OS = $(shell uname)
ifeq ($(OS), Darwin)
LEAK_CHECK = 
endif
ifeq ($(OS), Linux)
LEAK_CHECK = valgrind --leak-check=full -s -q 
endif
all: build

build: s21_cat

s21_cat:
	$(CC) $(CFLAG) -o s21_cat s21_cat.c

s21_cat_check: s21_cat
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

ifeq ($(OS), Darwin)
test: build
	bash test_cat_mac_os.sh
endif
ifeq ($(OS), Linux)	
test: build
	bash test_cat_linux.sh
endif

clean:
	@rm -rf txt*.txt s21_cat CPPLINT.cfg ../CPPLINT.cfg *.out