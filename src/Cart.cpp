#include "shoppingcart/Cart.hpp"
#include <iostream>

Cart::Cart() {}

void Cart::addItem(Product product, int quantity) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getProduct().getId() == product.getId()) {
            items[i].setQuantity(items[i].getQuantity() + quantity);
            return;
        }
    }
    items.push_back(CartItem(product, quantity));
}

void Cart::removeItem(int productId) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getProduct().getId() == productId) {
            items.erase(items.begin() + i);
            return;
        }
    }
}

void Cart::updateQuantity(int productId, int newQuantity) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getProduct().getId() == productId) {
            items[i].setQuantity(newQuantity);
            return;
        }
    }
}

double Cart::calculateTotal() const {
    double total = 0.0;
    for (size_t i = 0; i < items.size(); i++) {
        total += items[i].getSubtotal();
    }
    return total;
}

void Cart::viewCart() const {
    if (items.empty()) {
        std::cout << "Your cart is empty." << std::endl;
        return;
    }
    for (size_t i = 0; i < items.size(); i++) {
        items[i].displayItem();
    }
    std::cout << "Total: R" << calculateTotal() << std::endl;
}

void Cart::clearCart() {
    items.clear();
}

std::vector<CartItem> Cart::getItems() const {
    return items;
}

bool Cart::isEmpty() const {
    return items.empty();
}
