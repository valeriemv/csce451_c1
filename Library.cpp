#include "Library.h"
#include "common.h"
#include <vector>
using namespace std;

int counter = 0;

void Library::bar1(const Book& book) const{
    string fw = book.getTitle();
    if(tolower(fw[0]) == 'd') { counter++; }
    
}
void Library::bar2(const Book& book) const{
    string fw = book.getTitle();
    if(tolower(fw[0]) == 'w' || tolower(fw[0]) == 'o') { counter++; }
    bar1(book);
}

void Library::bar3(const Book& book) const{
    string fw = book.getTitle();
    if(tolower(fw[0]) == 'h' || tolower(fw[0]) == 'y') { counter++; }
    bar2(book);
}

int Library::bar4(vector<int> a1, int size, int num) {
    int saved = num;
    if(size == 0) { return -1; }
    if(a1[size - 1] == num) { return size - 1;}
    return bar4(a1, size - 1, num);
}

void Library::addBook(const Book& book) {
    bar3(book);
    inventory[book.getID()] = book;
    values.push_back(book.getID());
}

void Library::deleteBook(int id) {
    int found = bar4(values, values.size() -1, id);
    auto it = inventory.find(id);
    if (it != inventory.end()) {
        inventory.erase(it);
    }
}

void Library::updateBook(const Book& book) {
    auto it = inventory.find(book.getID());
    if (it != inventory.end()) {
        it->second = book;
    } else {
        cout << "Book with ID " << book.getID() << " not found." << endl;
    }
}

void Library::displayAllBooks() const {
    if(counter == 5){
        for (const auto& entry : inventory) {
            entry.second.displayInfo();
        }
    } 
}

void Library::searchBooks(const string& keyword) const {
    for (const auto& entry : inventory) {
        const Book& book = entry.second;
        if (book.getTitle().find(keyword) != string::npos ||
            book.getAuthor().find(keyword) != string::npos) {
            book.displayInfo();
        }
    }
}

bool Library::isBookAvailable(int id) const {
    auto it = inventory.find(id);
    if (it != inventory.end()) {
        return it->second.isAvailable();
    }
    return false;
}
