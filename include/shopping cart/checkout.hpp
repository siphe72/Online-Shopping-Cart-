#ifndef CHECKOUT_HPP
#define CHECKOUT_HPP

#include "shoppingcart/Cart.hpp"
#include "shoppingcart/Order.hpp"
#include "shoppingcart/ProductCatalog.hpp"

class Checkout {
public:
    Checkout();

    bool validateStock(Cart& cart, ProductCatalog& catalog);
    Order processCheckout(Cart& cart, ProductCatalog& catalog);
    void generateReceipt(Order& order);
};

#endif
