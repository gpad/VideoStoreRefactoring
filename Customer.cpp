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
                frequentRenterPoints += each.getFrequentRenterPoints();

                //show figures for this rental
                result << "\t" << each.getMovie().getTitle() << "\t" << each.getCharge() << "\n";
                totalAmount += each.getCharge();
        }
        //add footer lines
        result << "Amount owed is " << totalAmount << "\n";
        result << "You earned " << frequentRenterPoints << " frequent renter points";

        return result.str();
}
