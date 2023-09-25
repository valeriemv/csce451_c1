#include "Library.h"
#include <map>
#include <vector>
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

// Function to sort books alphabetically by author
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
