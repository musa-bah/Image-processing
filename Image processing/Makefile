CFLAGS = -c -std=c++17 -pedantic -Wall
CC = g++

image: main.o fileIO.o cmdLineCheck.o
		$(CC) -o image main.o fileIO.o cmdLineCheck.o
		
main.o: main.cpp imageHeader.h
		$(CC) $(CFLAGS) main.cpp

fileIO.o: fileIO.cpp imageHeader.h
		$(CC) $(CFLAGS) fileIO.cpp

cmdLineCheck.o: cmdLineCheck.cpp imageHeader.h
		$(CC) $(CFLAGS) cmdLineCheck.cpp

clean:
		rm *.o


