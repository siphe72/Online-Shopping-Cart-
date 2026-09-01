#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "shoppingcart/Cart.hpp"

class User {
private:
    std::string name;
    std::string email;
    std::string address;
    Cart cart;

public:
    User();
    User(std::string name, std::string email, std::string address);

    std::string getName() const;
    std::string getEmail() const;
    std::string getAddress() const;

    Cart& getCart();
};

#endif
