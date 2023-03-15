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

build: grep

grep:
	$(CC) $(CFLAG) -o grep grep.c

grep_check: grep
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	
ifeq ($(OS), Darwin)
test: build
	bash test_grep_mac_os.sh
endif
ifeq ($(OS), Linux)	
test: build
	bash test_grep_linux.sh
endif

clean:
	rm -rf txt*.txt grep *.out