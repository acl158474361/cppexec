PROGS = test

all: $(PROGS)

leptjson.o: leptjson.h leptjson.c
	gcc -g -c -o leptjson.o leptjson.c


test.o: test.c
	gcc -g -c -o test.o test.c

test: leptjson.o test.o
	gcc -g -o test test.o leptjson.o

