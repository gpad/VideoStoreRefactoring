#include "gmock/gmock.h"
#include "Rental.h"
using namespace testing;

TEST(RentalGetDaysRented, ReturnsDaysRented) {
        Movie movie("The Shawshank Redemption", Movie::REGULAR);
        Rental rental(movie, 10);
        ASSERT_THAT(rental.getDaysRented(), Eq(10));
}

TEST(RentalGetMovie, ReturnsMovieWithCorrectTitle) {
        Movie movie("The Shawshank Redemption", Movie::REGULAR);
        Rental rental(movie, 10);
        ASSERT_THAT(rental.getMovie().getTitle(), Eq("The Shawshank Redemption"));
}

TEST(RentalGetMovie, ReturnsMovieWithCorrectPriceCode) {
        Movie movie("The Shawshank Redemption", Movie::REGULAR);
        Rental rental(movie, 10);
        ASSERT_THAT(rental.getMovie().getPriceCode(), Eq(0));
}
