#include <iostream>
#include <unordered_map>
#include <string>
#include "library.cpp"
// #include "book.cpp"


using namespace std;

const string password = "password";

int main() {
    Library library;

    Book book1("Book 1", "Author 1");
    Book book2("Book 2", "Author 2");
    Book book3("Book 3", "Author 3");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.displayBooks();

    cout << "Checking availability of Book with ID 1234: " << (library.checkAvailability("1234") ? "Yes" : "No") << endl;

    library.deleteBook("2345");

    cout << "After deleting Book with ID 2345:" << endl;
    library.displayBooks();

    Book updatedBook("Updated Book 1", "Updated Author 1");
    library.updateBook("1234", updatedBook);

    cout << "After updating Book with ID 1234:" << endl;
    library.displayBooks();

    return 0;
}