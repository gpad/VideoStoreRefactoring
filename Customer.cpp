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
        std::ostringstream result;
        result << "Rental Record for " << getName() << "\n";

        for (auto each: rentals) {
                result << "\t" << each.getMovie().getTitle() << "\t" << each.getCharge() << "\n";
        }

        //add footer lines
        result << "Amount owed is " << getTotalAmount() << "\n";
        result << "You earned " << getTotalFrequentRenterPoints() << " frequent renter points";

        return result.str();
}

double Customer::getTotalAmount() const {
        double result = 0;

        for (auto each: rentals) {
                result += each.getCharge();
        }
        return result;
}

double Customer::getTotalFrequentRenterPoints() const {
        int result = 0;
        for (auto each: rentals) {
                result += each.getFrequentRenterPoints();
        }
        return result;
}
