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

std::string Customer::htmlStatement() {
        std::ostringstream result;
        result << "<H1>Rentals for <EM>" << getName() << "</EM></H1><P>" << "\n";

        for (auto each: rentals) {
                result << each.getMovie().getTitle() << ": " <<
                        each.getCharge()  << "<BR>" << "\n";
        }

        //add footer lines
        result << "<P>You owe <EM>" << getTotalAmount() << "</EM><P>" << "\n";
        result << "On this rental you earned <EM>" <<
                getTotalFrequentRenterPoints() << "</EM> frequent renter points<P>";

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
