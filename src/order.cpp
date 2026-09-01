#include "shoppingcart/Order.hpp"
#include <iostream>

int Order::nextOrderId = 1000;

Order::Order() : orderId(0), total(0.0), status("Pending") {}

Order::Order(std::vector<CartItem> items, double total)
    : items(items), total(total), status("Confirmed") {
    orderId = nextOrderId;
    nextOrderId++;
}

int Order::getOrderId() const {
    return orderId;
}

double Order::getTotal() const {
    return total;
}

std::string Order::getStatus() const {
    return status;
}

void Order::setStatus(std::string newStatus) {
    status = newStatus;
}

void Order::displayOrder() const {
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "Status: " << status << std::endl;
    for (size_t i = 0; i < items.size(); i++) {
        items[i].displayItem();
    }
    std::cout << "Total: R" << total << std::endl;
}
