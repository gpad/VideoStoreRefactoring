#include "Customer.h"
#include <sstream>

Customer::Customer(const std::string& name) : name(name) {
}

std::string Customer::getName() const {
        return name;
}

void Customer::addRental(const Rental& rental) {
        rentals.push_back(rental);
}

std::string Customer::statement() {
        double totalAmount = 0;
        int frequentRenterPoints = 0;

        std::ostringstream result;
        result << "Rental Record for " << getName() << "\n";

        for (auto each: rentals) {
                double thisAmount = 0;
                thisAmount = each.getCharge();

                //add frequent renter points
                frequentRenterPoints++;
                //add bonus for a 2 day new release rental
                if((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
                   (each.getDaysRented() > 1)) frequentRenterPoints++;


                //show figures for this rental
                result << "\t" << each.getMovie().getTitle() << "\t" << thisAmount << "\n";
                totalAmount += thisAmount;
        }
        //add footer lines
        result << "Amount owed is " << totalAmount << "\n";
        result << "You earned " << frequentRenterPoints << " frequent renter points";

        return result.str();
}
