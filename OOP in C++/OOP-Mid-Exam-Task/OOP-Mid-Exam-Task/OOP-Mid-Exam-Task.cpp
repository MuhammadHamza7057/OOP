#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class to represent each book
class Book {
private:
    string title;
    int inventory;
    double price;

public:
    Book(string t, int inv, double p) : title(t), inventory(inv), price(p) {}

    string getTitle() const { return title; }
    int getInventory() const { return inventory; }
    double getPrice() const { return price; }

    // Method to decrease inventory when book is added to the cart
    void decreaseInventory(int quantity) {
        if (inventory >= quantity)
            inventory -= quantity;
        else
            cout << "Insufficient inventory for " << title << endl;
    }
};

// ShoppingCart class to manage the cart
class ShoppingCart {
private:
    vector<Book> cart;

public:
    // Method to add book to cart
    void addToCart(const Book& book) {
        cart.push_back(book);
        cout << book.getTitle() << " added to cart." << endl;
    }

    // Method to view cart contents
    void viewCart() {
        cout << "Cart Contents:" << endl;
        for (const Book& book : cart) {
            cout << "- " << book.getTitle() << " ($" << book.getPrice() << ")" << endl;
        }
    }

    // Method to proceed with checkout
    void checkout() {
        double total = 0;
        for (const Book& book : cart) {
            total += book.getPrice();
        }
        cout << "Total: $" << total << endl;
        cart.clear(); // Empty the cart after checkout
        cout << "Thank you for your purchase!" << endl;
    }
};

int main() {
    // Sample books
    Book book1("Book 1", 10, 20.99);
    Book book2("Book 2", 15, 15.49);
    Book book3("Book 3", 5, 30.00);

    // ShoppingCart object
    ShoppingCart cart;

    int choice;
    do {
        cout << "\n\n\t\tWelcome to Hamza Book Store\n";
        cout << "\t\t********************************\n";
        cout << "\n\t\t1. Add a book to cart\n\t\t2. View cart\n\t\t3. Proceed to checkout\n\t\t4. Exit\n\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int bookChoice;
            cout << "\nEnter the book number you want to add to cart(1,2 & 3): ";
            cin >> bookChoice;
            
            switch (bookChoice) {
            case 1:
                cart.addToCart(book1);
                break;
            case 2:
                cart.addToCart(book2);
                break;
            case 3:
                cart.addToCart(book3);
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
            break;
        }
        case 2:
            cart.viewCart();
            break;
        case 3:
            cart.checkout();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
	


    return 0;
}
