#include "Library.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    //Admin password protection
    string adminFeaturesInput;
    string passwordInput;
    bool adminFeatures = false;

    cout << "Are you using admin features? Type \"Y\" for yes." << endl;
    cin >> adminFeaturesInput;

    if (adminFeaturesInput == "Y") { //yes to admin features
        cout << "Please type in the password:" << endl;
        cin >> passwordInput;

        if (passwordInput == "password") { //password correct
            cout << "Password accepted. Admin features enabled." << endl;
            adminFeatures = true;
        }
        else { //password incorrect
            cout << "Password incorrect. Admin features will not be available." << endl;
        }
    }
    else { //no to admin features
        cout << "Input interpretted as \"No\". No admin features will be available." << endl;
    }
    
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
