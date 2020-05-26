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
                thisAmount = amountFor(each);

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

double Customer::amountFor(const Rental& aRental) const {
        double result = 0;

        switch(aRental.getMovie().getPriceCode()) {
        case Movie::REGULAR:
                result += 2.;
                if(aRental.getDaysRented() > 2)
                        result += (aRental.getDaysRented() - 2) * 1.5;
                break;

        case Movie::NEW_RELEASE:
                result += aRental.getDaysRented() * 3.;
                break;

        case Movie::CHILDRENS:
                result += 1.5;
                if(aRental.getDaysRented() > 3)
                        result += (aRental.getDaysRented() - 3) * 1.5;
                break;
        }
        return result;
}
