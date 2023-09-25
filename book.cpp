#include "Book.h"
using namespace std;

Book::Book(const string& t, const string& a)  
    : title(t), author(a), availability(true) {
    srand(time(nullptr));  // Seed the random number generator with current time
    ID = rand();
}

Book::Book(const string& t, const string& a, bool availability)
    : title(t), author(a), availability(availability) {
    srand(time(nullptr));  // Seed the random number generator with current time
    ID = rand();
}

Book::Book() : title("Unknown"), author("Unknown"), availability(true) {
    srand(time(nullptr));  // Seed the random number generator with current time
    ID = rand();
}

int Book::getID() const {
    return ID;
}

const string& Book::getTitle() const {
    return title;
}

const string& Book::getAuthor() const {
    return author;
}

bool Book::isAvailable() const {
    return availability;
}

void Book::setAvailability(bool avail) {
    availability = avail;
}

void Book::displayInfo() const {
    cout << "ID: " << ID << ", Title: " << title << ", Author: " << author
              << ", Availability: " << (availability ? "Available" : "Not Available") << endl;
}
