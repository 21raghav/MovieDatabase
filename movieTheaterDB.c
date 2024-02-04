#include <stdio.h>
#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"
#include "movieTheaterDB.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// this prints the help menu 
void printHelp() {
    printf("\nHelp:\n");
    printf("h - Print help\n");
    printf("q - Quit\n");
    printf("m - Control movies\n");
    printf("a - Control actors\n");
}

void mainMenu() {
    printf("\nMain Menu:\n");
    printf("h - Print help\n");
}



int main() {
    char choice;
// welcome message
    printf("*************************\n");
    printf("* 2211 Movie Cinema *\n");
    printf("*************************\n");
mainMenu();// display the main menu
    do {
        
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'h':
                printHelp();
                break;
            case 'q':
                printf("Exiting the program. All data will be lost.\n");
                break;
            case 'm':
                movieMenu();
                break;
            case 'a':
                actorMenu();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'q');

    return 0;
}
