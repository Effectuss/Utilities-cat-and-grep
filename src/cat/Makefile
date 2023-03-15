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

build: cat

cat:
	$(CC) $(CFLAG) -o cat cat.c

cat_check: cat
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
	@rm -rf txt*.txt cat CPPLINT.cfg ../CPPLINT.cfg *.out