#include <iostream>
#include <list>
#include <vector>

// C++98 does not allow containers to be initialized with data
void cpp98_initializerList()
{
    std::list<int> list98;

    for (int i = 1; i < 6; ++i)
    {
        list98.push_back(i);
    }
}

// C++11 allows containers to be initialized with data
void cpp11_initializerList()
{
    std::vector<int> vector {1, 2, 3, 4, 5};

    // C++11 can also initialize using objects with multiple member variables
    struct Person
    {
        std::string Name;
        std::string Hometown;
        std::string Profession;
    };

    std::vector<Person> personVector{{"Todd Howard", "Bethesda", "Professional Liar"},
                                     {"Guy Fieri", "Flavortown", "Professional Cook"},
                                     {"Thanos", "Titan", "Savior of the Universe"}};

    for (Person person : personVector)
    {
        std::cout << "Name: " << person.Name << ", Hometown: "
            << person.Hometown << ", Profession: " << person.Profession << std::endl;
    }
}