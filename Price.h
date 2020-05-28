#ifndef PRICE_H
#define PRICE_H

class Price {
public:
virtual ~Price() = default;
virtual int getPriceCode() const = 0;
virtual double getCharge(int daysRented) const = 0;
};

#endif //PRICE_H
