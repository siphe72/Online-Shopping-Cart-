#include "shoppingcart/Product.hpp"
#include <iostream>

Product::Product() : id(0), name(""), price(0.0), description(""), stock(0) {}

Product::Product(int id, std::string name, double price, std::string description, int stock)
    : id(id), name(name), price(price), description(description), stock(stock) {}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

std::string Product::getDescription() const {
    return description;
}

int Product::getStock() const {
    return stock;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setStock(int newStock) {
    stock = newStock;
}

void Product::reduceStock(int quantity) {
    if (quantity <= stock) {
        stock -= quantity;
    }
}

void Product::displayInfo() const {
    std::cout << "ID: " << id << " | Name: " << name
               << " | Price: R" << price
               << " | Stock: " << stock
               << " | " << description << std::endl;
}
