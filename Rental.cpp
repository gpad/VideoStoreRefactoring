#include "Rental.h"

Rental::Rental(const Movie &movie, int daysRented) : movie(movie), daysRented(daysRented) {
}

int Rental::getDaysRented() const {
        return daysRented;
}

const Movie& Rental::getMovie() const {
        return movie;
}
