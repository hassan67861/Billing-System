#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Product {
public:
    Product(std::string name, double price) : name(name), price(price) {}

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

private:
    std::string name;
    double price;
};

class ShoppingCart {
public:
    void addItem(const Product& product, int quantity) {
        items.push_back(std::pair<Product, int>(product, quantity));
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.first.getPrice() * item.second;
        }
        return total;
    }

    const std::vector<std::pair<Product, int>>& getItems() const {
        return items;
    }

private:
    std::vector<std::pair<Product, int>> items;
};

class Customer {
public:
    Customer(std::string name) : name(name) {}

    void addToCart(const Product& product, int quantity) {
        cart.addItem(product, quantity);
    }

    void printInvoice() const {
        std::cout << "Invoice for " << name << ":\n";
        for (const auto& item : cart.getItems()) {
            std::cout << item.first.getName() << " - " << item.first.getPrice()
                      << " x " << item.second << " = " << item.first.getPrice() * item.second << "\n";
        }
        std::cout << "Total: " << cart.calculateTotal() << "\n";
    }

private:
    std::string name;
    ShoppingCart cart;
};

int main() {
    // Getting product details from the user
    std::string productName;
    double productPrice;

    std::cout << "Enter product name: ";
    std::getline(std::cin, productName);

    std::cout << "Enter product price: ";
    std::cin >> productPrice;

    // Creating a product
    Product product(productName, productPrice);

    // Clearing the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Getting customer details from the user
    std::string customerName;

    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);

    // Creating a customer
    Customer customer(customerName);

    // Getting quantities from the user
    int quantity;

    std::cout << "Enter quantity for " << product.getName() << ": ";
    std::cin >> quantity;

    // Adding items to the shopping cart
    customer.addToCart(product, quantity);

    // Printing the invoice
    customer.printInvoice();

    return 0;
}
