PROGS = main
all: $(PROGS)

main: main.o coroutine.o schedule.o
	g++ -o main main.o coroutine.o schedule.o


schedule.o: schedule.cpp schedule.h
	g++ -c -o schedule.o schedule.cpp

coroutine.o: coroutine.cpp coroutine.h schedule.h
	g++ -c -o coroutine.o coroutine.cpp

clean:
	rm main.o coroutine.o schedule.o main