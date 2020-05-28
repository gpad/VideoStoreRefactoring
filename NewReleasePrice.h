#ifndef NEWRELEASEPRICE_H
#define NEWRELEASEPRICE_H
#include "Price.h"

class NewReleasePrice : public Price {
public:
virtual int getPriceCode() const;
double getCharge(int daysRented) const;
int getFrequentRenterPoints(int daysRented) const;
};

#endif //NEWRELEASEPRICE_H
