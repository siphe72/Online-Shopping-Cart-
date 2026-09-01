#include "shoppingcart/ProductCatalog.hpp"
#include <iostream>
#include <algorithm>

ProductCatalog::ProductCatalog() {}

void ProductCatalog::addProduct(Product product) {
    products.push_back(product);
}

Product* ProductCatalog::getProductById(int id) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getId() == id) {
            return &products[i];
        }
    }
    return nullptr;
}

std::vector<Product> ProductCatalog::searchByName(std::string keyword) const {
    std::vector<Product> results;
    std::string lowerKeyword = keyword;
    std::transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);

    for (size_t i = 0; i < products.size(); i++) {
        std::string lowerName = products[i].getName();
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        if (lowerName.find(lowerKeyword) != std::string::npos) {
            results.push_back(products[i]);
        }
    }
    return results;
}

void ProductCatalog::listAllProducts() const {
    for (size_t i = 0; i < products.size(); i++) {
        products[i].displayInfo();
    }
}
