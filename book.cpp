#include "Book.h"
#include <chrono>
using namespace std;

namespace {
    static int IDCounter = 1;
}

Book::Book(const string& t, const string& a)  
    : title(t), author(a), availability(true) {
    auto now = chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();
    
    ID = IDCounter++ * 1000 + millis % 1000;
}

Book::Book(const string& t, const string& a, bool availability)
    : title(t), author(a), availability(availability) {
    auto now = chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();
    
    ID = IDCounter++ * 1000 + millis % 1000;
}

Book::Book() : title("Unknown"), author("Unknown"), availability(true) {
    auto now = chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();
    
    ID = IDCounter++ * 1000 + millis % 1000;
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

void Book::setTitle(string t) {
    title = t;
}
void Book::setAuthor(string a) {
    author = a;
}
