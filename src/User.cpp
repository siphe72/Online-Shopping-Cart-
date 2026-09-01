#include "shoppingcart/User.hpp"

User::User() : name(""), email(""), address("") {}

User::User(std::string name, std::string email, std::string address)
    : name(name), email(email), address(address) {}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getAddress() const {
    return address;
}

Cart& User::getCart() {
    return cart;
}
