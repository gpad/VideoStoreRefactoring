#ifndef PRICE_H
#define PRICE_H

class Price {
public:
virtual ~Price() {};
virtual int getPriceCode() const = 0;
};

#endif //PRICE_H
