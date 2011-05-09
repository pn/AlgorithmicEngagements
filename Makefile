PROFOPTS=-fprofile-arcs -ftest-coverage
CCOPTS=-g -lm -static
TARGETS=tul wie
CC=gcc

tul: tul.c
	gcc $(PROFOPTS) $(CCOPTS) tul.c -o tul
wie: wie.c
	gcc $(PROFOPTS) $(CCOPTS) wie.c -o wie
wie.test: wie
	./wie < wie.in > wie.out
	gcov wie.c
clean:
	rm -f *.gcda *.gcno *.gcov *.out $(TARGETS)
