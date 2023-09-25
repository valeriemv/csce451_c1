#include "Library.h"
using namespace std;

void Library::addBook(const Book& book) {
    inventory[book.getID()] = book;
}

void Library::deleteBook(int id) {
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
    for (const auto& entry : inventory) {
        entry.second.displayInfo();
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

void Library::sortBooksByTitle() {
    // Implement sorting logic here (e.g., using sort)
    map<string, vector<Book>> titleMap;
    for (const auto& entry : inventory) {
        const Book& book = entry.second;
        titleMap[book.getTitle()].push_back(book);
    }

    for (const auto& entry : titleMap) {
        for (const auto& book : entry.second) {
            book.displayInfo();
        }
    }
}

void Library::sortBooksByAuthor() {
    // Implement sorting logic here (e.g., using sort)
    map<string, vector<Book>> authorMap;
    for (const auto& entry : inventory) {
        const Book& book = entry.second;
        authorMap[book.getAuthor()].push_back(book);
    }

    for (const auto& entry : authorMap) {
        for (const auto& book : entry.second) {
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
