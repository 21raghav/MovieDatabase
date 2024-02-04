CC = gcc

# compiler flags, including -Wall for enabling common warning messages
CFLAGS = -Wall

# Default target: builds the movieTheaterDb executable
all: movieTheaterDB

# target: movieTheaterDB
# dependencies: movieTheaterDB.c, movieTheaterDB_movie.c, movieTheaterDB_actor.c
movieTheaterDB: movieTheaterDB.c movieTheaterDB_movie.c movieTheaterDB_actor.c
	$(CC) $(CFLAGS) -o movieTheaterDB movieTheaterDB.c movieTheaterDB_movie.c movieTheaterDB_actor.c

# removes the movieTheaterDB executable
clean:
	rm -f movieTheaterDB
