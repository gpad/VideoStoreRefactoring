#include "Movie.h"
#include "RegularPrice.h"
#include "ChildrensPrice.h"
#include "NewReleasePrice.h"

Movie::Movie(const std::string &title, const int priceCode) : title(title) {
        setPriceCode(priceCode);
}

int Movie::getPriceCode() const {
        return price->getPriceCode();
}

void Movie::setPriceCode(const int priceCode) {
        switch(priceCode) {
        case REGULAR:
                price = new RegularPrice;
                break;
        case NEW_RELEASE:
                price = new NewReleasePrice;
                break;
        case CHILDRENS:
                price = new ChildrensPrice;
                break;
        default:
                throw std::invalid_argument("Incorrect Price Code");
        }
}

std::string Movie::getTitle() const {
        return title;
}

double Movie::getCharge(int daysRented) const {
        return price->getCharge(daysRented);
}

int Movie::getFrequentRenterPoints(int daysRented) const {
        if((getPriceCode() == NEW_RELEASE) &&
           (daysRented > 1)) return 2;

        return 1;
}
