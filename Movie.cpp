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

double Movie::getCharge(int daysRented) const {
        double result = 0;

        switch(getPriceCode()) {
        case Movie::REGULAR:
                result += 2.;
                if(daysRented > 2)
                        result += (daysRented - 2) * 1.5;
                break;

        case Movie::NEW_RELEASE:
                result += daysRented * 3.;
                break;

        case Movie::CHILDRENS:
                result += 1.5;
                if(daysRented > 3)
                        result += (daysRented - 3) * 1.5;
                break;
        }
        return result;
}
