# C++ Shopping Cart System

## Overview
This is a console-based shopping cart system implemented in C++. It allows users to browse products, add items to the cart with quantities, remove items, view the cart with an itemized bill, and checkout with a total amount calculation.

## Features
- Display a list of available products.
- Add products to the shopping cart, updating quantity if already added.
- Remove products from the cart by product ID.
- View the current cart with product details and subtotal.
- Checkout to display the total and clear the cart.
- User-friendly console menu for interaction.

## Explanation of Key Methods

### `addProduct(const Product& p, int qty = 1)`
Adds the specified quantity of a product to the cart. If the product already exists in the cart, its quantity is updated. Otherwise, it is added as a new item. Provides feedback about the addition or update.

### `removeProduct(int productId)`
Removes the product with the given ID from the cart. If the product is found, it is erased from the cart vector. If not found, an appropriate message is displayed.

### `showCart()`
Displays the contents of the cart in a tabular format with columns for product ID, name, quantity, and subtotal price. Also calculates and displays the total price of all cart items. If the cart is empty, it notifies the user.

### `checkout()`
Calls `showCart()` to display the current cart contents, then thanks the user for shopping and clears the cart, resetting the shopping session.

### `showProducts(const vector<Product>& products)`
Displays all available products with their IDs, names, and prices so the user can browse what’s available for purchase.

## How to Use

1. Compile the C++ file with a standard compiler (g++, clang++, or IDE like Dev-C++/Visual Studio).
2. Run the executable.
3. Use the menu to browse products, add or remove items, show your cart, checkout, or exit the program.

## Sample Menu
Menu:

1. Browse Products

2. Add to Cart

3. Remove from Cart

4. Show Cart

5. Checkout

6. Exit
   
Enter your choice:

## Dependencies
- Standard C++ libraries (`iostream`, `vector`, `string`, `iomanip`)

## Example Products Included
- Laptop (₹50000)
- Smartphone (₹20000)
- Headphones (₹2500)
- Keyboard (₹1200)
- Mouse (₹800)
