#ifndef ACTOR_DATABASE_H
#define ACTOR_DATABASE_H
// structure for actor
struct Actor {
    int actorCode;
    char actorName[50];
    int age;
    char imdbProfile[50];
    struct Actor* next;
};
// external and functional variables
extern struct Actor* actorList;
extern struct Actor actorDatabase[100];
extern int actorCount;
void clearInputBuffer();
void addActor();
void searchActor();
void updateActor();
void eraseActor();
void printActors();

#endif /* ACTOR_DATABASE_H */
