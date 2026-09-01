#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>
#include <string>
#include "shoppingcart/CartItem.hpp"

class Order {
private:
    static int nextOrderId;
    int orderId;
    std::vector<CartItem> items;
    double total;
    std::string status;

public:
    Order();
    Order(std::vector<CartItem> items, double total);

    int getOrderId() const;
    double getTotal() const;
    std::string getStatus() const;

    void setStatus(std::string newStatus);
    void displayOrder() const;
};

#endif
