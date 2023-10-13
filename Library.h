#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <unordered_map>
#include <vector>

class Library {
private:
    std::unordered_map<int, Book> inventory;
    std::vector<int> values;
    

public:
    void bar1(const Book& book) const;
    void bar2(const Book& book) const;
    void bar3(const Book& book) const;
    int bar4(std::vector<int> a1, int size, int num);
    void addBook(const Book& book);
    void deleteBook(int id);
    void updateBook(const Book& book);
    void displayAllBooks() const;
    void searchBooks(const std::string& keyword) const;
    void sortBooksByTitle();
    void sortBooksByAuthor();
    bool isBookAvailable(int id) const;
};

#endif
