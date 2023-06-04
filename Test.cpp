#include "doctest.h"
#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace ariel;


TEST_CASE("Check MagicalContainer functions"){
    MagicalContainer container;
    CHECK(container.size() == 0);

    container.addElement(1);
    CHECK(container.size() == 1);

    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    CHECK_NE(container.size(), 0);
    CHECK_EQ(container.size(), 4);

    CHECK_NOTHROW(container.addElement(5));
    CHECK(container.size() == 5);

    container.addElement(1);
    CHECK(container.size() == 5);

    CHECK_THROWS(container.removeElement(6));
    container.addElement(6);
    CHECK_NOTHROW(container.removeElement(6));

    container.removeElement(1);
    container.removeElement(2);
    CHECK(container.size() != 4);
    CHECK(container.size() == 3);
    container.removeElement(2);
    CHECK_EQ(container.size(), 2);
}

TEST_CASE("Check AscendingIterator functions"){
    MagicalContainer container;
    SUBCASE("Checking AscendingIterator"){
        container.addElement(5);
        container.addElement(3);
        container.addElement(1);
        container.addElement(4);
        container.addElement(2);
        MagicalContainer::AscendingIterator ascending(container);
        auto begin = ascending.begin();

        CHECK(*begin == 1);
        ++begin;
        CHECK(*begin == 2);
        ++begin;
        CHECK(*begin == 3);
        ++begin;
        CHECK(*begin == 4);
        ++begin;
        CHECK(*begin == 5);
    }

    SUBCASE("Checking == && != operators"){
        container.addElement(5);
        container.addElement(3);
        container.addElement(1);
        MagicalContainer::AscendingIterator ascending1(container);
        MagicalContainer::AscendingIterator ascending2(container);
        MagicalContainer::AscendingIterator ascending3(container);        
        
        CHECK_FALSE(ascending1 != ascending2);
        CHECK(ascending1 == ascending2);  
        ++ascending1;
        CHECK(ascending1 != ascending2);
        CHECK_FALSE(ascending1 == ascending3);
        CHECK(ascending2 == ascending3);
        ++ascending3;
        ++ascending3;
        CHECK(ascending2 != ascending3);
    }

    SUBCASE("Checking comparison operators") {
        container.addElement(5);
        container.addElement(3);
        container.addElement(1);
        container.addElement(4);
        container.addElement(2);
        MagicalContainer::AscendingIterator ascending(container);
        auto begin = ascending.begin();
        auto end = ascending.end();
        
        CHECK(begin == begin);
        CHECK_FALSE(end != end);
        CHECK(begin != end);
        CHECK_FALSE(end == begin);
        CHECK(begin < end);
        CHECK_FALSE(begin > end);
    }
    
}

TEST_CASE("Check SideCrossIterator functions"){
    MagicalContainer container;
    SUBCASE("Checking SideCrossIterator"){
        container.addElement(5);
        container.addElement(3);
        container.addElement(1);
        container.addElement(4);
        container.addElement(2);
        MagicalContainer::SideCrossIterator side(container);
        auto begin = side.begin();

        CHECK(*begin == 1);
        ++begin;
        CHECK(*begin == 5);
        ++begin;
        CHECK(*begin == 2);
        ++begin;
        CHECK(*begin == 4);
        ++begin;
        CHECK(*begin == 3);
    }

    SUBCASE("Checking == && != operators"){
        container.addElement(5);
        container.addElement(3);
        container.addElement(1);
        MagicalContainer::SideCrossIterator side1(container);
        MagicalContainer::SideCrossIterator side2(container);
        MagicalContainer::SideCrossIterator side3(container);        
        
        CHECK_FALSE(side1 != side2);
        CHECK(side1 == side2);  
        ++side1;
        CHECK(side1 != side2);
        CHECK_FALSE(side1 == side3);
        CHECK(side2 == side3);
        ++side3;
        ++side3;
        CHECK(side2 != side3);
    }

    SUBCASE("Checking comparison operators") {
        container.addElement(5);
        container.addElement(3);
        container.addElement(1);
        container.addElement(4);
        container.addElement(2);
        MagicalContainer::SideCrossIterator side(container);
        auto begin = side.begin();
        auto end = side.end();

        CHECK(begin == begin);
        CHECK_FALSE(end != end);
        CHECK(begin != end);
        CHECK_FALSE(end == begin);
        CHECK(begin < end);
        CHECK_FALSE(begin > end);
    }
    
}

TEST_CASE("Check PrimeIterator functions"){
    MagicalContainer container;
    SUBCASE("Checking PrimeIterator"){
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(7);
        container.addElement(9);
        MagicalContainer::PrimeIterator prime(container);
        auto begin = prime.begin();
        auto end = prime.end();

        CHECK(*begin == 3);
        ++begin;
        CHECK(*begin == 5);
        ++begin;
        CHECK(*begin == 7);
        ++begin;
        CHECK(begin == prime.end());
    }

    SUBCASE("Checking == && != operators"){
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        MagicalContainer::PrimeIterator prime1(container);
        MagicalContainer::PrimeIterator prime2(container);
        MagicalContainer::PrimeIterator prime3(container);        
        
        CHECK_FALSE(prime1 != prime2);
        CHECK(prime1 == prime2);  
        ++prime1;
        CHECK(prime1 != prime2);
        CHECK_FALSE(prime1 == prime3);
        CHECK(prime2 == prime3);
        ++prime3;
        CHECK(prime1 == prime3);
        CHECK(prime3 == prime3.end());
    }

    SUBCASE("Checking comparison operators") {
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(7);
        container.addElement(9);
        MagicalContainer::PrimeIterator prime(container);
        auto begin = prime.begin();
        auto end = prime.end();

        CHECK(begin == begin);
        CHECK_FALSE(end != end);
        CHECK(begin != end);
        CHECK_FALSE(end == begin);
        CHECK(begin < end);
        CHECK_FALSE(begin > end);
        ++begin;
        ++begin;
        CHECK(*begin == *end);
    }
    
}

