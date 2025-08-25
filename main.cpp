#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

struct CartItem {
    Product product;
    int quantity;
};

class ShoppingCart {
    vector<CartItem> cart;

public:
    void addProduct(const Product& p, int qty = 1) {
        for (auto& item : cart) {
            if (item.product.id == p.id) {
                item.quantity += qty;
                cout << p.name << " updated in cart.\n";
                return;
            }
        }
        cart.push_back({p, qty});
        cout << p.name << " added to cart.\n";
    }

    void removeProduct(int productId) {
        for (auto it = cart.begin(); it != cart.end(); ++it) {
            if (it->product.id == productId) {
                cout << it->product.name << " removed from cart.\n";
                cart.erase(it);
                return;
            }
        }
        cout << "Product not found in cart.\n";
    }

    void showCart() {
        cout << "\nYour Cart:\n";
        if (cart.empty()) {
            cout << "Cart is empty.\n";
            return;
        }

        double total = 0;
        cout << left << setw(10) << "ID" << setw(20) << "Product"
             << setw(10) << "Qty" << setw(10) << "Price" << endl;

        for (const auto& item : cart) {
            double subtotal = item.product.price * item.quantity;
            total += subtotal;
            cout << left << setw(10) << item.product.id << setw(20)
                 << item.product.name << setw(10) << item.quantity
                 << setw(10) << subtotal << endl;
        }
        cout << "Total: Rs. " << total << endl;
    }

    void checkout() {
        showCart();
        cout << "\nThank you for shopping!\n";
        cart.clear();
    }
};

void showProducts(const vector<Product>& products) {
    cout << "\nAvailable Products:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << endl;
    for (const auto& p : products) {
        cout << left << setw(10) << p.id << setw(20) << p.name << setw(10) << p.price << endl;
    }
}

int main() {
    vector<Product> products = {
        {1, "Laptop", 50000.0},
        {2, "Smartphone", 20000.0},
        {3, "Headphones", 2500.0},
        {4, "Keyboard", 1200.0},
        {5, "Mouse", 800.0}
    };

    ShoppingCart cart;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Browse Products\n2. Add to Cart\n3. Remove from Cart\n4. Show Cart\n5. Checkout\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            showProducts(products);
        } else if (choice == 2) {
            int id, qty;
            showProducts(products);
            cout << "Enter Product ID to add: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> qty;
            bool found = false;
            for (const auto& p : products) {
                if (p.id == id) {
                    cart.addProduct(p, qty);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Invalid product ID.\n";
        } else if (choice == 3) {
            int id;
            cart.showCart();
            cout << "Enter Product ID to remove: ";
            cin >> id;
            cart.removeProduct(id);
        } else if (choice == 4) {
            cart.showCart();
        } else if (choice == 5) {
            cart.checkout();
            break;
        } else if (choice == 6) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}