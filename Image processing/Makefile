CFLAGS = -c -std=c++17 -pedantic -Wall
CC = g++

image: main.o fileIO.o cmdLineCheck.o memory.o
		$(CC) -o image main.o fileIO.o cmdLineCheck.o memory.o
		
main.o: main.cpp imageHeader.h
		$(CC) $(CFLAGS) main.cpp

fileIO.o: fileIO.cpp imageHeader.h
		$(CC) $(CFLAGS) fileIO.cpp

cmdLineCheck.o: cmdLineCheck.cpp imageHeader.h
		$(CC) $(CFLAGS) cmdLineCheck.cpp

memory.o: memory.cpp imageHeader.h
		$(CC) $(CFLAGS) memory.cpp

clean:
		rm *.o


