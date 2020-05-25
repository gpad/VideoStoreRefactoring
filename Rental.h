#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
Rental(const Movie &movie, int daysRented);
int getDaysRented() const;
const Movie& getMovie() const;

private:
Movie movie;
int daysRented;
};

#endif //RENTAL_H
