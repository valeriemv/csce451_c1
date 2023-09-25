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

void Library::updateBook(const int ID, string title, string author, bool availability) {
    auto it = inventory.find(ID);
    if (it != inventory.end()) {
        if (title != "")
            it->second.setTitle(title);
        if (author != "")
            it->second.setAuthor(author);

        it->second.setAvailability(availability);
    } else {
        cout << "Book with ID " << ID << " not found." << endl;
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
    
}

// Function to sort books alphabetically by author
void Library::sortBooksByAuthor() {
    
}

// Function to sort books by ID
void Library::sortBooksById() {
    
}

bool Library::isBookAvailable(int id) const {
    auto it = inventory.find(id);
    if (it != inventory.end()) {
        return it->second.isAvailable();
    }
    return false;
}
