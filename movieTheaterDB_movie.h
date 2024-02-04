#ifndef MOVIE_THEATER_DB_MOVIE
#define MOVIE_THEATER_DB_MOVIE
// structure for  movie
struct Movie {
    int movieCode;
    char movieName[100];
    char genre[25];
    float rating;
    struct Movie* next;
};
//external and functional declarations

extern struct Movie* movieList;
extern struct Movie movieDatabase[100];
extern int movieCount;
void clearInputBuffer();
void addMovie();
void searchMovie();
void updateMovie();
void eraseMovie(); 
void printMovies();

#endif /* MOVIE_THEATER_DB_MOVIE */
