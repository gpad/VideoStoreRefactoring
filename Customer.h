#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Rental.h"

class Customer {
public:
explicit Customer(const std::string &name);
std::string getName() const;
void addRental(const Rental& rental);
std::string statement();

private:
std::string name;
std::vector<Rental> rentals;
double amountFor(const Rental& aRental) const;
double getTotalAmount() const;
double getTotalFrequentRenterPoints() const;
};

#endif //CUSTOMER_H
