#ifndef CHILDRENSPRICE_H
#define CHILDRENSPRICE_H
#include "Price.h"

class ChildrensPrice : public Price {
public:
virtual int getPriceCode() const;
double getCharge(int daysRented) const;
};

#endif //CHILDRENSPRICE_H
