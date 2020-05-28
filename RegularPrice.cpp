#include "Movie.h"
#include "RegularPrice.h"

int RegularPrice::getPriceCode() const {
        return Movie::REGULAR;
}

double RegularPrice::getCharge(int daysRented) const {
        double result = 0;
        result += 2.;
        if(daysRented > 2)
                result += (daysRented - 2) * 1.5;
        return result;
}
