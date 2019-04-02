#include <iostream>
#include <list>
#include <vector>

// Show this before container improvements

// C++98 does not allow containers to be initialized with data
void cpp98_initializerList()
{
    std::list<int> list98;

    for (int i = 1; i < 6; ++i)
    {
        list98.push_back(i);
    }
}

struct aStruct
{
    int anInt;
    std::string aString;
};

// C++11 does allow containers to be initialized with data
void cpp11_initializerList()
{
    std::list<int> list11 {1, 2, 3, 4, 5};

    // C++11 can also initialize using objects with multiple member variables
    std::vector<aStruct> structVector {{1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}};
}