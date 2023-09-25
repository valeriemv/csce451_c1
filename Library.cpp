#include "Library.h"

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
    }
}

void Library::displayAllBooks() const {
    for (const auto& entry : inventory) {
        entry.second.displayInfo();
    }
}

void Library::searchBooks(const std::string& keyword) const {
    for (const auto& entry : inventory) {
        const Book& book = entry.second;
        if (book.getTitle().find(keyword) != std::string::npos ||
            book.getAuthor().find(keyword) != std::string::npos) {
            book.displayInfo();
        }
    }
}

void Library::sortBooksByTitle() {
    // Implement sorting logic here (e.g., using std::sort)
}

void Library::sortBooksByAuthor() {
    // Implement sorting logic here (e.g., using std::sort)
}

bool Library::isBookAvailable(int id) const {
    auto it = inventory.find(id);
    if (it != inventory.end()) {
        return it->second.isAvailable();
    }
    return false;
}
