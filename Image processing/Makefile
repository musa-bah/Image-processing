CFLAGS = -c -std=c++17 -pedantic -Wall
CC = g++

image: main.o fileIO.o cmd_line_check.o
		$(CC) -o image main.o fileIO.o cmd_line_check.o
		
main.o: main.cpp imageHeader.h
		$(CC) $(CFLAGS) main.cpp

fileIO.o: fileIO.cpp imageHeader.h
		$(CC) $(CFLAGS) fileIO.cpp

cmd_line_check.o: cmd_line_check.cpp imageHeader.h
		$(CC) $(CFLAGS) cmd_line_check.cpp

clean:
		rm main.o fileIO.o cmd_line_check.o


