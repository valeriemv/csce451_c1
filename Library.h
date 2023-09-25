#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <unordered_map>

class Library {
private:
    std::unordered_map<int, Book> inventory;

public:
    void addBook(const Book& book);
    void deleteBook(int id);
    void updateBook(const int ID, std::string title, std::string author, bool availability);
    void displayAllBooks() const;
    void searchBooks(const std::string& keyword) const;
    void sortBooksByTitle();
    void sortBooksByAuthor();
    void sortBooksById();
    bool isBookAvailable(int id) const;
};

#endif
