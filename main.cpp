#include "Library.h"
#include "common.h"
#include <iostream>
#include <string.h>
using namespace std;


int main() {
    string adminFeaturesInput;
    string passwordInput;
    bool adminFeatures = false;

    std::cout << "Are you using admin features? Type \"Y\" for yes" << std::endl;
    std::cin >> adminFeaturesInput;

    if(adminFeaturesInput == "Y"){ 
        std::cout << "Please type in the password: " << std::endl;
        std::cin >> passwordInput;

        if(passwordInput == "password") { 
            std::cout << "Password accepted. Admin features enabled." << std::endl;
            adminFeatures = true;
        } else {
            std::cout << "Password incorrect. Admin feature will not be available." << std::endl;
        }

    } else { 
        std::cout << "Input interpretted as \"No\". No admin features will be available." << std::endl;
        // cout << "Searching for books with 'Book':" << endl;
        // library.searchBooks("Book");
        // cout << endl;

        // cout << "Checking if Book 1 is available:" << endl;
        // cout << (library.isBookAvailable(book1.getID()) ? "Available" : "Not Available") << endl;
        // cout << endl;
    }

    Library library;

    while(adminFeatures == true){ // admin
        int option = 0;
        cout << "Please select an option:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Delete a book" << endl;
        cout << "3. Update a book" << endl;
        cout << "4. Display all books" << endl;
        cout << "5. exit option" << endl;
        cin >> option;
        if(option == 1){
            string bookTitle;
            string author;
            cout << "Enter a book" << endl;
            cin.ignore();
            getline(cin, bookTitle);
        
            cout << "Enter a author" << endl;
            cin.clear();
            getline(cin, author);

            Book book1(bookTitle, author);
            library.addBook(book1);

            cout << endl;
            cout << "Book was added" << endl;
            cout << endl;
        } else if(option == 2){
            int deletedid = 0;
            cout << "Enter the id of book:";
            cin >> deletedid;
            library.deleteBook(deletedid);
            cout << endl;
            cout << "Book was deleted" << endl;
            cout << endl;
        } else if(option == 3){
            cout << "Book was updated" << endl;
            cout << endl;
        } else if(option == 4){
            cout << "Displaying all books:" << endl;
            library.displayAllBooks();
            cout << endl;
        } else if(option == 5){
            adminFeatures = false;
            cout << endl;
        }
    } 

    return 0;
}
