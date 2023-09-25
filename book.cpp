#include "Book.h"

Book::Book(int id, const std::string& t, const std::string& a) 
    : ID(id), title(t), author(a), availability(true) {}

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
