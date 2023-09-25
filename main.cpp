#include "Library.h"
using namespace std;

int main() {
    Library library;

    Book book1("Book A", "Author X");
    Book book2("Book B", "Author Y");

    library.addBook(book1);
    library.addBook(book2);

    cout << "Displaying all books:" << endl;
    library.displayAllBooks();
    cout << endl;

    cout << "Searching for books with 'Book':" << endl;
    library.searchBooks("Book");
    cout << endl;

    cout << "Updating book availability:" << endl;
    library.updateBook(Book("Book A", "Author X"));
    library.updateBook(Book("Book B", "Author Y", false));
    cout << endl;

    cout << "Checking if Book 1 is available:" << endl;
    cout << (library.isBookAvailable(book1.getID()) ? "Available" : "Not Available") << endl;
    cout << endl;

    return 0;
}
