#ifndef PRICE_H
#define PRICE_H

class Price {
public:
virtual ~Price() = default;
virtual int getPriceCode() const = 0;
double getCharge(int daysRented) const;
};

#endif //PRICE_H
