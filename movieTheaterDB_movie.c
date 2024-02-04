

#include "movieTheaterDB_movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// global variables
struct Movie* movieList = NULL;
struct Movie movieDatabase[100];
int movieCount = 0;
//functiont to add movie to the database
void addMovie() {
    if (movieCount >= 100) {
        printf("The movie list is full. Cannot add more movies.\n");
        return;
    }

    struct Movie newMovie;
    int code;

    // Input movie code 
    do {
        printf("Enter movie code: ");
        scanf("%d", &code);

        if (code <= 0) {
            printf("Movie code must be a positive integer.\n");
        } else {
            int codeExists = 0;
            for (int i = 0; i < movieCount; i++) {
                if (movieDatabase[i].movieCode == code) {
                    codeExists = 1;
                    break;
                }
            }
            if (codeExists) {
                printf("Movie code already exists. Please choose a different code.\n");
            } else {
                newMovie.movieCode = code;
                break;
            }
        }
    } while (1);

      do {
        printf("Enter movie name (up to 100 characters): ");
        scanf(" %[^\n]s", newMovie.movieName);

        if (strlen(newMovie.movieName) > 100) {
            printf("Movie name is too long. Please enter a name up to 100 characters.\n");
        } else {
            break;
        }
    } while (1);


   do {
        printf("Enter movie genre (up to 25 characters): ");
        scanf(" %[^\n]s", newMovie.genre);

        if (strlen(newMovie.genre) > 25) {
            printf("Movie genre is too long. Please enter a genre up to 25 characters.\n");
        } else {
            break;
        }
    } while (1);
    
    // Input movie rating (between 0.0 and 10.0)
    do {
        printf("Enter movie rating (between 0.0 and 10.0): ");
        scanf("%f", &newMovie.rating);
        if (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
            printf("Invalid rating. Please enter a rating between 0.0 and 10.0.\n");
        } else {
            break;
        }
    } while (1);

    // Add the movie to the database
    movieDatabase[movieCount] = newMovie;
    movieCount++;

    printf("Movie added .\n");
}
// search for movie by code 
void searchMovie() {
    int searchCode;
    printf("Enter the movie code to search: ");
    scanf("%d", &searchCode);

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movieDatabase[i].movieCode == searchCode) {
            printf("Movie Code: %d\n", movieDatabase[i].movieCode);
            printf("Movie Name: %s\n", movieDatabase[i].movieName);
            printf("Movie Genre: %s\n", movieDatabase[i].genre);
            printf("Movie Rating: %.1f\n", movieDatabase[i].rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}
// update movie details
void updateMovie() {
    int updateCode;
    printf("Enter the movie code to update: ");
    scanf("%d", &updateCode);

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movieDatabase[i].movieCode == updateCode) {
            printf("Enter updated movie details:\n");
            addMovie(); // Reuse the addMovie function to update the movie
            movieDatabase[i] = movieDatabase[movieCount - 1]; // Overwrite the old movie with the updated one
            movieCount--;
            found = 1;
            printf("Movie updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}
// erase a movie from the database
void eraseMovie() {
    int eraseCode;
    printf("Enter the movie code to erase: ");
    scanf("%d", &eraseCode);

    int found = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movieDatabase[i].movieCode == eraseCode) {
            // Erase the movie by shifting elements in the array
            for (int j = i; j < movieCount - 1; j++) {
                movieDatabase[j] = movieDatabase[j + 1];
            }
            movieCount--;

            printf("Movie erased successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found. Unable to erase.\n");
    }
}
// print all the movies
void printMovies() {
    if (movieCount == 0) {
        printf("No movies in the database.\n");
        return;
    }

    printf("Movie Code   Movie Name                 Movie Genre               Movie Rating\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%-12d %-25s %-24s %.1f\n", movieDatabase[i].movieCode, movieDatabase[i].movieName, movieDatabase[i].genre, movieDatabase[i].rating);
    }
}

void movieMenu() {
    char choice;

    do {
        printf("\nMovie Management:\n");
        printf("i - Insert a new movie\n");
        printf("s - Search for a movie\n");
        printf("u - Update a movie\n");
        printf("e - Erase a movie\n");
        printf("p - Print all movies\n");
        printf("q - Quit Movie Management\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        clearInputBuffer();

        switch (choice) {
            case 'i':
                addMovie();
                break;
            case 's':
                searchMovie();
                break;
            case 'u':
                updateMovie();
                break;
            case 'e':
                eraseMovie();
                break;
            case 'p':
                printMovies();
                break;
            case 'q':
                printf("Exiting Movie Management.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'q');
}