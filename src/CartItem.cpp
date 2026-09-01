#include "shoppingcart/CartItem.hpp"
#include <iostream>

CartItem::CartItem() : product(), quantity(0) {}

CartItem::CartItem(Product product, int quantity) : product(product), quantity(quantity) {}

Product CartItem::getProduct() const {
    return product;
}

int CartItem::getQuantity() const {
    return quantity;
}

void CartItem::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

double CartItem::getSubtotal() const {
    return product.getPrice() * quantity;
}

void CartItem::displayItem() const {
    std::cout << product.getName() << " x" << quantity
               << " = R" << getSubtotal() << std::endl;
}
