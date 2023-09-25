#include "Library.h"
#include <iostream>
#include <string>
using namespace std;

void populateLibrary(Library& library);

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

    populateLibrary(library);

    cout << "Displaying all books:" << endl;
    library.displayAllBooks();
    cout << endl;

    cout << "Searching for books with 'Book':" << endl;
    library.searchBooks("Book");
    cout << endl;

    library.sortBooksByAuthor();
    library.displayAllBooks();
    cout << endl;

    library.sortBooksByTitle();
    library.displayAllBooks();
    cout << endl;

    // cout << "Updating book availability:" << endl;
    // library.updateBook(book2.getID(), "Book A", "Author B", true);
    // library.updateBook(4, "Book B", "Author Y", false);
    // cout << endl;

    // cout << "Checking if Book 1 is available:" << endl;
    // cout << (library.isBookAvailable(book1.getID()) ? "Available" : "Not Available") << endl;
    // cout << endl;

    return 0;
}

void populateLibrary(Library& library) {
    string titles[] = {
        "The Catcher in the Rye", "To Kill a Mockingbird", "1984", "The Great Gatsby", "One Hundred Years of Solitude",
        "Brave New World", "Rebecca", "Romeo and Juliet", "Yankee in King Arthur's Court", "Moby-Dick",
        "War and Peace", "Crime and Punishment", "The Odyssey", "Hamlet", "The Iliad", "The Rainbow",
        "Wuthering Heights", "Frankenstein", "Alice's Adventures in Wonderland", "The Grapes of Wrath",
        "Anna Karenina", "Heart of Darkness", "The Scarlet Letter", "Don Quixote", "The Picture of Dorian Gray",
        "The Sound and the Fury", "The Count of Monte Cristo", "Ulysses", "A Tale of Two Cities", "Les Misérables",
        "Gone with the Wind", "The Brothers Karamazov", "A Christmas Carol", "Jane Eyre",
        "Little Women", "Dracula", "Great Expectations", "Mansfield Park", "Sense and Sensibility", "The Three Musketeers",
        "Treasure Island", "The Adventures of Sherlock Holmes", "Walden", "The War of the Worlds", "The Time Machine",
        "Oliver Twist", "Yankee in King Arthur's Court", "Peter Pan", "Moll Flanders", "The Hound of the Baskervilles", "Robinson Crusoe"
    };

    string authors[] = {
        "J.D. Salinger", "Harper Lee", "George Orwell", "F. Scott Fitzgerald", "Gabriel Garcia Marquez", "Aldous Huxley",
        "Daphne du Maurier", "William Shakespeare", "Mark Twain", "Herman Melville", "Leo Tolstoy", "Fyodor Dostoevsky",
        "Homer", "William Shakespeare", "Homer", "Dante Alighieri", "Emily Brontë", "Mary Shelley", "Lewis Carroll",
        "John Steinbeck", "Leo Tolstoy", "Joseph Conrad", "Nathaniel Hawthorne", "Miguel de Cervantes", "Oscar Wilde",
        "William Faulkner", "Alexandre Dumas", "James Joyce", "Charles Dickens", "Victor Hugo", "Margaret Mitchell",
        "Fyodor Dostoevsky", "Charles Dickens", "Charlotte Brontë", "Louisa May Alcott", "Bram Stoker", "Charles Dickens",
        "Charlotte Brontë", "Charlotte Brontë", "Alexandre Dumas", "Robert Louis Stevenson", "Arthur Conan Doyle",
        "Henry David Thoreau", "H.G. Wells", "H.G. Wells", "Charles Dickens", "Rudyard Kipling", "J.M. Barrie",
        "Daniel Defoe", "Arthur Conan Doyle"
    };

    for(int i = 0; i < titles->size(); i++) {
        Book newBook(titles[i], authors[i]);
        library.addBook(newBook);
    }
}