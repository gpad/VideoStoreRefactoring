#include "Movie.h"
#include "NewReleasePrice.h"

int NewReleasePrice::getPriceCode() const {
        return Movie::NEW_RELEASE;
}

double NewReleasePrice::getCharge(int daysRented) const {
        double result = 0;
        result += daysRented * 3.;
        return result;
}
