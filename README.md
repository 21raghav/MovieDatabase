**Movie Theater Database System**

This C program is a movie database system developed to manage information about movies and actors. The system incorporates dynamic memory management, linked lists, and file I/O to provide functionality for inserting, updating, searching, and erasing entries.

**Features**

Dynamic Memory Management: The program efficiently manages memory allocation for an arbitrary number of movies and actors.

Linked Lists: Linked lists are utilized to organize and store information about movies, actors, and their relationships.

File I/O: The system supports reading from and writing to files, allowing users to save and load their movie database.

Modularization with Makefile: The program is modularized into separate files, promoting better organization and maintainability. The included Makefile streamlines the compilation process.

Movie-Actor Relationship Structure: An advanced feature is the inclusion of a movie-actor relationship structure, providing a more comprehensive representation of the data.

Database Dump and Restore: Users can dump the database to a file and later restore it, ensuring data persistence and flexibility.


**Files Structure**

main.c: Main program logic.

movie.h: Header file containing structures and function declarations related to movies.

movie.c: Implementation of functions related to movies.

actor.h: Header file containing structures and function declarations related to actors.

actor.c: Implementation of functions related to actors.

relationship.h: Header file containing structures and function declarations related to movie-actor relationships.

relationship.c: Implementation of functions related to movie-actor relationships.

file_io.h: Header file containing functions for reading from and writing to files.

file_io.c: Implementation of file I/O functions.

makefile: Makefile for easy compilation.
