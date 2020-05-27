#ifndef NEWRELEASEPRICE_H
#define NEWRELEASEPRICE_H
#include "Price.h"

class NewReleasePrice : public Price {
public:
virtual int getPriceCode() const;
};

#endif //NEWRELEASEPRICE_H
