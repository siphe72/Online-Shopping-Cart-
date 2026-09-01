#ifndef PRODUCTCATALOG_HPP
#define PRODUCTCATALOG_HPP

#include <vector>
#include "shoppingcart/Product.hpp"

class ProductCatalog {
private:
    std::vector<Product> products;

public:
    ProductCatalog();

    void addProduct(Product product);
    Product* getProductById(int id);
    std::vector<Product> searchByName(std::string keyword) const;
    void listAllProducts() const;
};

#endif
