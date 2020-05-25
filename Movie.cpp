#include "Movie.h"

Movie::Movie(const std::string &title, const int priceCode) : priceCode(priceCode), title(title) {
}

int Movie::getPriceCode() const {
        return priceCode;
}

void Movie::setPriceCode(const int priceCode) {
        this->priceCode = priceCode;
}

std::string Movie::getTitle() const {
        return title;
}
