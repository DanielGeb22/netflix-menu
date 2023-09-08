#include <iostream>
#include <string>
using namespace std;

struct movieNode {
    movieNode(): data(""), date(0, 0, 0), prev(nullptr), next(nullptr) {}   // Movie Constructor
    movieNode(string d): data(d), date(), prev(nullptr), next(nullptr) {}   // Movie Constructor with given name
    movieNode(string d, Date movieDate, movieNode* prv, movieNode* nxt) {   // Movie Constructor with given name, date, and pointers to previous and next movies in the list
        data = d; 
        date = movieDate;
        prev = prv;
        next = nxt;
    }
    string data;    // Movie name
    Date date;      // Movie release date
    movieNode* prev;
    movieNode* next;
};

class movies {  // Double linked list implementation for Movies
    public:
        movies(): head(nullptr), tail(nullptr) {}   // Movie List Constructor
        void addMovie(string title, Date date);     // Function that adds movie to a list
        void deleteMoviesBeforeDate(Date date);     // Function that deletes movies before a certain date in a movie list
        int getMovieIndex(string name);             // Function that returns the index of a specific movie in a list
        void printMovies();                         // Function that prints the movies in a movie list
        movieNode* getHead();                       // Gets the head of a movie list

    private:
        movieNode* head;
        movieNode* tail;
};

void movies::addMovie(string title, Date date) {
    movieNode* temp = new movieNode();
    if (head == nullptr && tail == nullptr) {
        head = temp;
        tail = head;
    }

    temp->data = title;
    temp->date = date;

    tail->next = temp;
    temp->prev = tail;
    tail = tail->next;
    head->prev = nullptr;
}


void movies::deleteMoviesBeforeDate(Date date) {
    movieNode* current = head;
    movieNode* temp = new movieNode();

    while (current != nullptr) {
        if (current->date.isLessThan(date)) {
            temp = current;
            if (current->prev != nullptr){ 
                current->prev->next = current->next;
            }
            if (current->next != nullptr){
                current->next->prev = current->prev;
            }
            current = current->next;
            if (temp == head) {
                head = current;
            }
            if (temp == tail) {
                tail = tail->prev;
            }
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

int movies::getMovieIndex(string name) {
    movieNode* current = head;
    int i = -1;
    while (current->next != nullptr) {
        if (current->data == name) {
            return i+1;
        }
        current = current->next;
        i++;
    }
    return i+1;
}

void movies::printMovies() {
    if (head == nullptr) {
        return;
    }
    movieNode* current = head;
    while (current != nullptr) {
        cout << current->data << " (" << current->date.GetMonth() << "/" << current->date.GetDay() << "/" << current->date.GetYear() << ")" << endl;
        current = current->next;
    }
}

movieNode* movies::getHead() {
    return head;
}