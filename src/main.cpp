#include <iostream>
#include "shoppingcart/Product.hpp"
#include "shoppingcart/ProductCatalog.hpp"
#include "shoppingcart/Cart.hpp"
#include "shoppingcart/User.hpp"
#include "shoppingcart/Checkout.hpp"
#include "shoppingcart/Order.hpp"

int main() {
    ProductCatalog catalog;
    catalog.addProduct(Product(1, "Baby Blanket", 250.0, "Soft cotton blanket", 10));
    catalog.addProduct(Product(2, "Feeding Bottle", 120.0, "BPA-free bottle", 20));
    catalog.addProduct(Product(3, "Diaper Pack", 300.0, "Pack of 50 diapers", 15));

    User user("Avuyile", "avuyile@example.com", "123 Main Street");
    Checkout checkout;

    int choice = -1;

    while (choice != 0) {
        std::cout << std::endl << "1. Browse Products" << std::endl;
        std::cout << "2. Add Item to Cart" << std::endl;
        std::cout << "3. View Cart" << std::endl;
        std::cout << "4. Checkout" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            catalog.listAllProducts();
        } else if (choice == 2) {
            int id, quantity;
            std::cout << "Enter product ID: ";
            std::cin >> id;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            Product* product = catalog.getProductById(id);
            if (product != nullptr) {
                user.getCart().addItem(*product, quantity);
                std::cout << "Item added to cart." << std::endl;
            } else {
                std::cout << "Product not found." << std::endl;
            }
        } else if (choice == 3) {
            user.getCart().viewCart();
        } else if (choice == 4) {
            Order order = checkout.processCheckout(user.getCart(), catalog);
            if (order.getOrderId() != 0) {
                checkout.generateReceipt(order);
            }
        } else if (choice != 0) {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    std::cout << "Thank you for shopping." << std::endl;
    return 0;
}
