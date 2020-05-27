#include "Rental.h"

Rental::Rental(const Movie &movie, int daysRented) : movie(movie), daysRented(daysRented) {
}

double Rental::getCharge() const {
        return movie.getCharge(daysRented);
}

int Rental::getDaysRented() const {
        return daysRented;
}

const Movie& Rental::getMovie() const {
        return movie;
}

int Rental::getFrequentRenterPoints() const {
        return movie.getFrequentRenterPoints(daysRented);
}
