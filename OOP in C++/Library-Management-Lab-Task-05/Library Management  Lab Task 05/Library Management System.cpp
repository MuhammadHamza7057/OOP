#include <iostream>
#include <string>
#include <vector>
#include <limits> // for numeric_limits

using namespace std;

// Define the Book class to represent a book with title, author, and publication year
class Book {
public:
    string title;
    string author;
    int year;

    // Constructor to initialize the Book object with provided details
    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};

// Define the Library class to manage a collection of books
class Library {
private:
    vector<Book> books; // Vector to store the books in the library

public:
    // Function to add a book to the library
    void addBook(Book b) {
        books.push_back(b); // Add the provided book to the collection
    }

    // Function to remove a book from the library based on its title
    void removeBook(string title) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& b) { return b.title == title; });
        if (it != books.end()) {
            books.erase(it); // Remove the book from the collection
            cout << "Book \"" << title << "\" has been removed from the library." << endl;
        }
        else {
            cout << "Book \"" << title << "\" not found in the library." << endl;
        }
    }

    // Function to display all books in the library
    void listBooks() {
        if (books.empty()) {
            cout << "The library is empty." << endl;
            return;
        }
        cout << "Books in the library:" << endl;
        for (const auto& book : books) {
            // Display title, author, and publication year of each book
            cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << endl;
        }
    }
};

int main() {
    // Create a Library object
    Library myLibrary;

    // Menu-based user interface
    int choice;
    string title, author;
    int year;

    do {
        cout << "\n\n\t\t\t\t***Library Management System***\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        cout << "Menu:\n";
        cout << "1. Add a Book\n";
        cout << "2. Remove a Book\n";
        cout << "3. List All Books\n";
        cout << "4. Exit\n";
        cout << "\n\n\t\t\t\tEnter your choice: ";

        // Check if the input is valid (i.e., it's an integer)
        if (!(cin >> choice)) {
            // If input is not an integer, clear the error state and discard invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue; // Skip the rest of the loop and start over
        }

        switch (choice) {
        case 1:
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Publication Year: ";
            while (!(cin >> year)) { // Loop until a valid integer is entered
                cout << "Invalid input. Please enter a valid year: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            myLibrary.addBook(Book(title, author, year));
            cout << "Book added successfully." << endl;
            break;
        case 2:
            cout << "Enter the title of the book to remove: ";
            cin.ignore();
            getline(cin, title);
            myLibrary.removeBook(title);
            break;
        case 3:
            myLibrary.listBooks();
            break;
        case 4:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
