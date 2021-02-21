#include "gmock/gmock.h"
#include "Customer.h"
using namespace testing;

TEST(CustomerGetName, ReturnsCustomerName)
{
        Customer customer("Dimitris Palioselitis");
        ASSERT_THAT(customer.getName(), Eq("Dimitris Palioselitis"));
}

TEST(CustomerStatement, ReturnsCorrectStatementExampleOne)
{
        Customer customer("Dimitris Palioselitis");
        Movie shawshank("The Shawshank Redemption");
        shawshank.setPriceCode(Movie::REGULAR);
        Movie toystory("Toy Story");
        toystory.setPriceCode(Movie::CHILDRENS);
        Movie oldboy("OldBoy");
        oldboy.setPriceCode(Movie::NEW_RELEASE);
        Rental r_shawshank(shawshank, 10);
        Rental r_toystory(toystory, 5);
        Rental r_oldboy(oldboy, 3);
        customer.addRental(r_shawshank);
        customer.addRental(r_toystory);
        customer.addRental(r_oldboy);
        std::stringstream result;
        result << "Rental Record for Dimitris Palioselitis"
               << "\n"
               << "\t"
               << "The Shawshank Redemption"
               << "\t"
               << "14"
               << "\n"
               << "\t"
               << "Toy Story"
               << "\t"
               << "4.5"
               << "\n"
               << "\t"
               << "OldBoy"
               << "\t"
               << "9"
               << "\n"
               << "Amount owed is 27.5"
               << "\n"
               << "You earned 4 frequent renter points";
        ASSERT_THAT(customer.statement(), Eq(result.str()));
}

TEST(CustomerStatement, ReturnsCorrectStatementExampleTwo)
{
        Customer customer("Dimitrios Palioselitis");
        Movie shawshank("The Shawshank Redemption");
        shawshank.setPriceCode(Movie::REGULAR);
        Movie toystory("Toy Story");
        toystory.setPriceCode(Movie::CHILDRENS);
        Rental r_shawshank(shawshank, 10);
        Rental r_toystory(toystory, 5);
        customer.addRental(r_toystory);
        customer.addRental(r_shawshank);
        std::stringstream result;
        result << "Rental Record for Dimitrios Palioselitis"
               << "\n"
               << "\t"
               << "Toy Story"
               << "\t"
               << "4.5"
               << "\n"
               << "\t"
               << "The Shawshank Redemption"
               << "\t"
               << "14"
               << "\n"
               << "Amount owed is 18.5"
               << "\n"
               << "You earned 2 frequent renter points";
        ASSERT_THAT(customer.statement(), Eq(result.str()));
}

TEST(CustomerStatement, ReturnsCorrectStatementExampleThree)
{
        Customer customer("D. Palioselitis");
        Movie oldboy("OldBoy");
        oldboy.setPriceCode(Movie::NEW_RELEASE);
        Rental r_oldboy(oldboy, 12);
        customer.addRental(r_oldboy);
        std::stringstream result;
        result << "Rental Record for D. Palioselitis"
               << "\n"
               << "\t"
               << "OldBoy"
               << "\t"
               << "36"
               << "\n"
               << "Amount owed is 36"
               << "\n"
               << "You earned 2 frequent renter points";
        ASSERT_THAT(customer.statement(), Eq(result.str()));
}

TEST(CustomerStatement, ReturnsCorrectStatementExampleFour)
{
        Customer customer("2998763");
        std::stringstream result;
        result << "Rental Record for 2998763"
               << "\n"
               << "Amount owed is 0"
               << "\n"
               << "You earned 0 frequent renter points";
        ASSERT_THAT(customer.statement(), Eq(result.str()));
}

TEST(CustomerStatementHtml, ReturnsCorrectStatementExampleOne)
{
        Customer customer("Dimitris Palioselitis");
        Movie shawshank("The Shawshank Redemption");
        shawshank.setPriceCode(Movie::REGULAR);
        Movie toystory("Toy Story");
        toystory.setPriceCode(Movie::CHILDRENS);
        Movie oldboy("OldBoy");
        oldboy.setPriceCode(Movie::NEW_RELEASE);
        Rental r_shawshank(shawshank, 10);
        Rental r_toystory(toystory, 5);
        Rental r_oldboy(oldboy, 3);
        customer.addRental(r_shawshank);
        customer.addRental(r_toystory);
        customer.addRental(r_oldboy);
        std::stringstream result;
        result << "<H1>Rentals for <EM>Dimitris Palioselitis</EM></H1><P>"
               << "\n"
               << "The Shawshank Redemption: 14<BR>"
               << "\n"
               << "Toy Story: 4.5<BR>"
               << "\n"
               << "OldBoy: 9<BR>"
               << "\n"
               << "<P>You owe <EM>27.5</EM><P>"
               << "\n"
               << "On this rental you earned <EM>4</EM> frequent renter points<P>";
        ASSERT_THAT(customer.htmlStatement(), Eq(result.str()));
}

TEST(CustomerStatementHtml, ReturnsCorrectStatementExampleTwo)
{
        Customer customer("Dimitrios Palioselitis");
        Movie shawshank("The Shawshank Redemption");
        shawshank.setPriceCode(Movie::REGULAR);
        Movie toystory("Toy Story");
        toystory.setPriceCode(Movie::CHILDRENS);
        Rental r_shawshank(shawshank, 10);
        Rental r_toystory(toystory, 5);
        customer.addRental(r_toystory);
        customer.addRental(r_shawshank);
        std::stringstream result;
        result << "<H1>Rentals for <EM>Dimitrios Palioselitis</EM></H1><P>"
               << "\n"
               << "Toy Story: 4.5<BR>"
               << "\n"
               << "The Shawshank Redemption: 14<BR>"
               << "\n"
               << "<P>You owe <EM>18.5</EM><P>"
               << "\n"
               << "On this rental you earned <EM>2</EM> frequent renter points<P>";
        ASSERT_THAT(customer.htmlStatement(), Eq(result.str()));
}

TEST(CustomerStatementHtml, ReturnsCorrectStatementExampleThree)
{
        Customer customer("D. Palioselitis");
        Movie oldboy("OldBoy");
        oldboy.setPriceCode(Movie::NEW_RELEASE);
        Rental r_oldboy(oldboy, 12);
        customer.addRental(r_oldboy);
        std::stringstream result;
        result << "<H1>Rentals for <EM>D. Palioselitis</EM></H1><P>"
               << "\n"
               << "OldBoy: 36<BR>"
               << "\n"
               << "<P>You owe <EM>36</EM><P>"
               << "\n"
               << "On this rental you earned <EM>2</EM> frequent renter points<P>";
        ASSERT_THAT(customer.htmlStatement(), Eq(result.str()));
}

TEST(CustomerStatementHtml, ReturnsCorrectStatementExampleFour)
{
        Customer customer("2998763");
        std::stringstream result;
        result << "<H1>Rentals for <EM>2998763</EM></H1><P>"
               << "\n"
               << "<P>You owe <EM>0</EM><P>"
               << "\n"
               << "On this rental you earned <EM>0</EM> frequent renter points<P>";
        ASSERT_THAT(customer.htmlStatement(), Eq(result.str()));
}
