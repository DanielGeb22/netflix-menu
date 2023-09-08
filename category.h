#include <iostream>
#include <string>

using namespace std;

struct categoryNode {
    categoryNode(): data(""), movieList(new movies()), prev(nullptr), next(nullptr) {}  // Category Constructor
    categoryNode(string d): data(d), movieList(nullptr), prev(nullptr), next(nullptr) {}    // Category Constructor with given name
    categoryNode(string d, movies* list, categoryNode* prv, categoryNode* nxt): data(d), movieList(list), prev(prv), next(nxt) {}   // Category Constructor with given name, movie list, and pointers to next and previous categories
    string data;
    movies* movieList;
    categoryNode* prev;
    categoryNode* next;
};

class categories {      // Double linked list implementation for the categories
    public:
        categories(): head(nullptr), tail(nullptr) {}   // Category list Constructor
        void addCategory(string name);                  // Function that adds a category to the category list
        void searchCategory(string name);               // Function that searches for a certain category in the category list and prints whether it's been found or not
        void searchMovie(string name);                  // Function that searches for a certain movie in all categories
        void removeCategory(string name);               // Function that removes a specific category from the category list
        void addMovieToCategory(string category, string title, Date date);  // Function that adds a certain movie with a release date to a certain category
        void deleteAllMoviesBeforeDate(Date date);      // Function that deletes movies before a certain date
        void printAllMovies();                          // Funciton that prints all movies from all categories
        categoryNode* getHead();                        // Function that gets the head of the category list
    
    private:
        categoryNode* head;
        categoryNode* tail;
};

void categories::addCategory(string name) {
    categoryNode* temp = new categoryNode();
    if (head == nullptr && tail == nullptr) {
        head = temp;
        tail = head;
    }
    
    temp->data = name;

    tail->next = temp;
    temp->prev = tail;
    tail = tail->next;
    head->prev = nullptr;
}

void categories::searchCategory(string name) {
    categoryNode* current = head;
    while (current != nullptr) {
        if (current->data == name) {
            cout << "Category " << name << " was found" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Category " << name << " was not found" << endl;
}

// Works but need to implement using Binary Search
void categories::searchMovie(string title) { 
    categoryNode* current = head;
    while (current != nullptr) {
        movieNode* temp = current->movieList->getHead();
        while (temp != nullptr) {
            if (temp->data == title) {
                cout << "The movie " << title << " was found" << endl;
                return;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    cout << "The movie " << title << " was not found" << endl;
}

void categories::removeCategory(string name) {
    categoryNode* current = head;
    categoryNode* temp = new categoryNode();

    if (current->data == name) {
        temp = current->next;
        temp->prev = nullptr;
        head = temp;
        delete current;
        return;
    }

    while (current->next != nullptr) {
        if (current->data == name) {
            temp = current->prev;
            temp->next = current->next;
            current->next->prev = temp;
            delete current;
            break;
        }
        current = current->next;
    }

    if (current->next == nullptr && current->data == name) {
        temp = current->prev;
        temp->next = nullptr;
        tail = temp;
        delete current;
    }
}

void categories::addMovieToCategory(string category, string title, Date date) {
    categoryNode* ptr = head;
    while (ptr != nullptr) {
        if(ptr->data == category) {
            ptr->movieList->addMovie(title, date);
        }
        ptr = ptr->next;
    }
}

void categories::deleteAllMoviesBeforeDate(Date date) {
    categoryNode* current = head;
    while (current != nullptr) {
        current->movieList->deleteMoviesBeforeDate(date);
        current = current->next;
    }
}

void categories::printAllMovies() {
    categoryNode* current = head;
    while (current != nullptr) {
        current->movieList->printMovies();
        current = current->next;
    }
}

categoryNode* categories::getHead() {
    return head;
}