.PHONY : all, fclean

all : rush02.h *.c
	gcc -o rush-02 *.c

fclean : rush-02.out
	rm -f rush-02

