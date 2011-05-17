#PROFOPTS=-fprofile-arcs -ftest-coverage
PROFOPTS=
CCOPTS=-O0 -lm -static -Wall -ggdb
TARGETS=tul wie wsp prz sis
CC=clang

all: $(TARGETS)

tul: tul.c
	$(CC) $(PROFOPTS) $(CCOPTS) tul.c -o tul
wie: wie.c
	$(CC) $(PROFOPTS) $(CCOPTS) wie.c -o wie
wsp: wsp.c
	$(CC) $(PROFOPTS) $(CCOPTS) wsp.c -o wsp
prz: prz.c
	$(CC) $(PROFOPTS) $(CCOPTS) prz.c -o prz
sis: sis.c
	$(CC) $(PROFOPTS) $(CCOPTS) sis.c -o sis
wie.test: wie
	./wie < wie.in > wie.out
	gcov wie.c
wsp.test2:
	./wsp < wsp.in
	for x in `seq 1 6`; do ./wsp < testy.wsp/$$x.in > testy.wsp/$$x.out_; done
gengraph:
	./gengraph | dot -Tpng | display

.PHONY: clean gengraph
clean:
	rm -f *.gcda *.gcno *.gcov *.out $(TARGETS)
