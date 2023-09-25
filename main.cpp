#include "Library.h"

int main() {
    Library library;

    Book book1(1, "Book A", "Author X");
    Book book2(2, "Book B", "Author Y");

    library.addBook(book1);
    library.addBook(book2);

    std::cout << "Displaying all books:" << std::endl;
    library.displayAllBooks();

    std::cout << "\nSearching for books with 'Book':" << std::endl;
    library.searchBooks("Book");

    std::cout << "\nUpdating book availability:" << std::endl;
    library.updateBook(Book(1, "Book A", "Author X"));
    library.updateBook(Book(2, "Book B", "Author Y", false));

    std::cout << "\nChecking if Book 1 is available:" << std::endl;
    std::cout << (library.isBookAvailable(1) ? "Available" : "Not Available") << std::endl;

    return 0;
}
