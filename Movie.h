#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
public:
static const int CHILDRENS = 2;
static const int REGULAR = 0;
static const int NEW_RELEASE = 1;

Movie(const std::string &title, const int priceCode = 0);
void setPriceCode(const int priceCode);
int getPriceCode() const;
std::string getTitle() const;
double getCharge(int daysRented) const;
int getFrequentRenterPoints(int daysRented) const;

private:
int priceCode;
std::string title;
};

#endif //MOVIE_H
