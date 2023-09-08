#include <iostream>
#include <string>
#include "date.h"
#include "movie.h"
#include "category.h"
using namespace std;

int main() {
    // Created the Netflix Menu
    categories* netflixCategories = new categories();

    // Added Action, Animation, and Comedy categories to Netflix
    netflixCategories->addCategory("Action");
    netflixCategories->addCategory("Animation");
    netflixCategories->addCategory("Comedy");

    // Added 2 action movies on Netflix
    netflixCategories->addMovieToCategory("Action", "Mission: Impossible - Fallout", Date(7, 27, 2018));
    netflixCategories->addMovieToCategory("Action", "The Batman", Date(3, 4, 2022));

    // Added 2 animation movies on Netflix
    netflixCategories->addMovieToCategory("Animation", "Cars", Date(6, 9, 2006));
    netflixCategories->addMovieToCategory("Animation", "Monsters, Inc.", Date(11, 2, 2001));

    // Added 2 comedy movies to Netflix
    netflixCategories->addMovieToCategory("Comedy", "21 Jump Street", Date(3, 16, 2012));
    netflixCategories->addMovieToCategory("Comedy", "The Hangover", Date(6, 2, 2009));

    // Searches through all movies to determine whether or not the movies below are available on Netflix
    netflixCategories->searchMovie("The Batman");
    netflixCategories->searchMovie("Interstellar");
    netflixCategories->searchMovie("The Hangover");

    cout << endl;

    // Prints all movies on Netflix
    cout << "All Movies on Netflix: " << endl;
    netflixCategories->printAllMovies();
    cout << endl;

    // Deletes all movies released before January 1st, 2022
    netflixCategories->deleteAllMoviesBeforeDate(Date(1, 1, 2022));

    // Prints the updated movie library
    cout << "All Movies on Netflix: " << endl;
    netflixCategories->printAllMovies();
    cout << endl;

    // Gets the index of the movie "The Batman"
    cout << "The Batman's index is " << netflixCategories->getHead()->movieList->getMovieIndex("The Batman") << endl;
    
    // Searches the category list to determine whether or not the category "Comedy" is available on Netflix
    netflixCategories->searchCategory("Comedy");

    // Removes the category
    netflixCategories->removeCategory("Animation");
    cout << "Category Animation was successfully removed"<< endl << endl;

    // Checks whether or not Animation category is still available on Netflix, and it's indeed not there
    netflixCategories->searchCategory("Animation");
}


