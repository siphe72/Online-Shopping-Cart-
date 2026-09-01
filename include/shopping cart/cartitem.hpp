#ifndef CARTITEM_HPP
#define CARTITEM_HPP

#include "shoppingcart/Product.hpp"

class CartItem {
private:
    Product product;
    int quantity;

public:
    CartItem();
    CartItem(Product product, int quantity);

    Product getProduct() const;
    int getQuantity() const;

    void setQuantity(int newQuantity);
    double getSubtotal() const;

    void displayItem() const;
};

#endif
