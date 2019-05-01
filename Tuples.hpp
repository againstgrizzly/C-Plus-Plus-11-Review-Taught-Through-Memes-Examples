#include <tuple>
#include <iostream>

// Tuples are similar to pairs except they can have more than one
void tuples()
{
    typedef std::tuple<std::string, int, double> aTuple;

    aTuple tuple1("This is a tuple", 12, 3.4);

    // You can use std::get to either modify or retrieve the reference value at an index
    std::get<1>(tuple1) = 100;
    std::cout << std::get<1>(tuple1) << std::endl;

    // std::tie can be used to unpack a tuple
    std::string aString; int anInt; double aDouble;

    std::tie(aString, anInt, aDouble) = tuple1;
    std::cout << "String: " << aString << " Int: " << anInt << " Double: " << aDouble << std::endl;

    // You can also use std::ignore if you don't want to unpack the whole tuple
    std::tie(std::ignore, anInt, std::ignore) = tuple1;
    std::cout << "Only Int: " << anInt << std::endl;

    // Similar to std::make_pair, there exists a std::make_tuple
    std::tuple<std::string, std::string, double> tuple2 =
        std::make_tuple("This is another tuple", "This tuple has two strings and a double", 0.1);
}

// Topics not covered:
// std::tuple_element
// std::tuple_size
// std::forward_as_tuple
// std::tuple_cat