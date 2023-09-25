#include "Book.h"

Book::Book(const std::string& t, const std::string& a)  
    : title(t), author(a), availability(true) {
    srand(time(nullptr));  // Seed the random number generator with current time
    ID = rand() % 10000 + 1;  // Generate a random ID between 1 and 10000
}

Book::Book(const std::string& t, const std::string& a, bool availability)
    : title(t), author(a), availability(availability) {
    srand(time(nullptr));  // Seed the random number generator with current time
    ID = rand() % 10000 + 1;  // Generate a random ID between 1 and 10000
}

Book::Book() : title("Unknown"), author("Unknown"), availability(true) {
    srand(time(nullptr));  // Seed the random number generator with current time
    ID = rand() % 10000 + 1;  // Generate a random ID between 1 and 10000
}

int Book::getID() const {
    return ID;
}

const std::string& Book::getTitle() const {
    return title;
}

const std::string& Book::getAuthor() const {
    return author;
}

bool Book::isAvailable() const {
    return availability;
}

void Book::setAvailability(bool avail) {
    availability = avail;
}

void Book::displayInfo() const {
    std::cout << "ID: " << ID << ", Title: " << title << ", Author: " << author
              << ", Availability: " << (availability ? "Available" : "Not Available") << std::endl;
}
