#ifndef REGULARPRICE_H
#define REGULARPRICE_H
#include "Price.h"

class RegularPrice : public Price {
public:
virtual int getPriceCode() const;
};

#endif //REGULARPRICE_H
