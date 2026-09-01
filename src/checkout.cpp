#include "shoppingcart/Checkout.hpp"
#include <iostream>

Checkout::Checkout() {}

bool Checkout::validateStock(Cart& cart, ProductCatalog& catalog) {
    std::vector<CartItem> items = cart.getItems();
    for (size_t i = 0; i < items.size(); i++) {
        Product* product = catalog.getProductById(items[i].getProduct().getId());
        if (product == nullptr || product->getStock() < items[i].getQuantity()) {
            std::cout << "Insufficient stock for: " << items[i].getProduct().getName() << std::endl;
            return false;
        }
    }
    return true;
}

Order Checkout::processCheckout(Cart& cart, ProductCatalog& catalog) {
    if (cart.isEmpty()) {
        std::cout << "Cannot checkout an empty cart." << std::endl;
        return Order();
    }

    if (!validateStock(cart, catalog)) {
        std::cout << "Checkout failed due to insufficient stock." << std::endl;
        return Order();
    }

    std::vector<CartItem> items = cart.getItems();
    for (size_t i = 0; i < items.size(); i++) {
        Product* product = catalog.getProductById(items[i].getProduct().getId());
        if (product != nullptr) {
            product->reduceStock(items[i].getQuantity());
        }
    }

    Order order(items, cart.calculateTotal());
    cart.clearCart();
    return order;
}

void Checkout::generateReceipt(Order& order) {
    std::cout << "----- RECEIPT -----" << std::endl;
    order.displayOrder();
    std::cout << "-------------------" << std::endl;
}
