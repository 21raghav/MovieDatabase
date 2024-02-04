#include "movieTheaterDB_actor.h"
#include <stdio.h>
#include <string.h>
//global variables
struct Actor* actorList = NULL; 
struct Actor actorDatabase[100];
int actorCount = 0;
// add actor to the database
void addActor() {
    if (actorCount >= 100) {
        printf("The actor list is full. Cannot add more actors.\n");
        return;
    }

    struct Actor newActor;
    int code;

    // Input actor code
    do {
        printf("Enter actor code: ");
        scanf("%d", &code);

        if (code <= 0) {
            printf("Actor code must be a positive integer.\n");
        } else {
            int codeExists = 0;
            for (int i = 0; i < actorCount; i++) {
                if (actorDatabase[i].actorCode == code) {
                    codeExists = 1;
                    break;
                }
            }
            if (codeExists) {
                printf("Actor code already exists. Please choose a different code.\n");
            } else {
                newActor.actorCode = code;
                break;
            }
        }
    } while (1);

    // Input actor name (up to 50 characters)
    do {
        printf("Enter actor name (up to 50 characters): ");
        scanf(" %[^\n]s", newActor.actorName);

        if (strlen(newActor.actorName) > 50) {
            printf("Actor name is too long. Please enter a name up to 50 characters.\n");
        } else {
            break;
        }
    } while (1);

    // Input actor age (between 0 and 120)
    do {
        printf("Enter actor age: ");
        scanf("%d", &newActor.age);

        if (newActor.age < 0 || newActor.age > 120) {
            printf("Invalid age. Please enter an age between 0 and 120.\n");
        } else {
            break;
        }
    } while (1);

     // Input actor IMDB profile (up to 50 characters)
    do {
        printf("Enter actor IMDB profile (up to 50 characters): ");
        scanf(" %[^\n]s", newActor.imdbProfile);

        if (strlen(newActor.imdbProfile) > 50) {
            printf("IMDB profile is too long. Please enter a profile up to 50 characters.\n");
        } else {
            break;
        }
    } while (1);

    // Add the actor to the database
    actorDatabase[actorCount] = newActor;
    actorCount++;

    printf("Actor added.\n");
}
// searching for actor in the database
void searchActor() {
    int searchCode;
    printf("Enter the actor code to search: ");
    scanf("%d", &searchCode);

    int found = 0;
    for (int i = 0; i < actorCount; i++) {
        if (actorDatabase[i].actorCode == searchCode) {
            printf("Actor Code: %d\n", actorDatabase[i].actorCode);
            printf("Actor Name: %s\n", actorDatabase[i].actorName);
            printf("Actor Age: %d\n", actorDatabase[i].age);
            printf("Actor IMDB Profile: %s\n", actorDatabase[i].imdbProfile);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Actor not found.\n");
    }
}
// to update an actor in the database
void updateActor() {
    int updateCode;
    printf("Enter the actor code to update: ");
    scanf("%d", &updateCode);

    int found = 0;
    for (int i = 0; i < actorCount; i++) {
        if (actorDatabase[i].actorCode == updateCode) {
            printf("Enter updated actor details:\n");
            addActor(); // Reuse the addActor function to update the actor
            actorDatabase[i] = actorDatabase[actorCount - 1]; // Overwrite the old actor with the updated one
            actorCount--;
            found = 1;
            printf("Actor updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Actor not found.\n");
    }
}
// erasing a actor from the database
void eraseActor() {
    int eraseCode;
    printf("Enter the actor code to erase: ");
    scanf("%d", &eraseCode);

    int found = 0;
    for (int i = 0; i < actorCount; i++) {
        if (actorDatabase[i].actorCode == eraseCode) {
            // Erase the actor by shifting elements in the array
            for (int j = i; j < actorCount - 1; j++) {
                actorDatabase[j] = actorDatabase[j + 1];
            }
            actorCount--;

            printf("Actor erased successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Actor not found. Unable to erase.\n");
    }
}
// print all the actors in database
void printActors() {
    if (actorCount == 0) {
        printf("No actors in the database.\n");
        return;
    }

    printf("Actor Code   Actor Name                 Actor Age   Actor IMDB Profile\n");
    for (int i = 0; i < actorCount; i++) {
        printf("%-12d %-25s %-11d %-s\n", actorDatabase[i].actorCode, actorDatabase[i].actorName, actorDatabase[i].age, actorDatabase[i].imdbProfile);
    }
}

void actorMenu() {
    char choice;

    do {
        printf("\nActor Management:\n");
        printf("i - Insert a new actor\n");
        printf("s - Search for an actor\n");
        printf("u - Update an actor\n");
        printf("e - Erase an actor\n");
        printf("p - Print all actors\n");
        printf("q - Quit Actor Management\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        clearInputBuffer();

        switch (choice) {
            case 'i':
                addActor();
                break;
            case 's':
                searchActor();
                break;
            case 'u':
                updateActor();
                break;
            case 'e':
                eraseActor();
                break;
            case 'p':
                printActors();
                break;
            case 'q':
                printf("Exiting Actor Management.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'q');
}