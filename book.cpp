#include <string>
#include <iostream>

using namespace std;

class Book {
  int id;
  string title;
  string author;
  bool isAvailable;

  public:
  Book(int id, string title, string author, bool isAvailable) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->isAvailable = isAvailable;
  }

  void printBook() {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    
    cout << "Availability: ";
    if (isAvailable) 
      cout << "This title is available." << endl;
    else
      cout << "This title is unavailable." << endl;

  }

  void updateBook() {
    
  }
};