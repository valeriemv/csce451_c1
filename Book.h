#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    int ID;
    std::string title;
    std::string author;
    bool availability;

public:
    Book(int id, const std::string& t, const std::string& a);
    int getID() const;
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    bool isAvailable() const;
    void setAvailability(bool avail);
    void displayInfo() const;
};

#endif
