#ifndef CART_HPP
#define CART_HPP

#include <vector>
#include "shoppingcart/CartItem.hpp"

class Cart {
private:
    std::vector<CartItem> items;

public:
    Cart();

    void addItem(Product product, int quantity);
    void removeItem(int productId);
    void updateQuantity(int productId, int newQuantity);
    double calculateTotal() const;
    void viewCart() const;
    void clearCart();
    std::vector<CartItem> getItems() const;
    bool isEmpty() const;
};

#endif
