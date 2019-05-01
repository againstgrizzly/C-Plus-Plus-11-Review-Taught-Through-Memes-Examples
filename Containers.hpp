#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <forward_list>
#include <array>

// To delete an iterator from a map in C++98, you must create a temporary iterator, increment the original iterator, then erase from the map
void cpp98_mapErase()
{
    std::map<int, std::string> map98;

    for (int i = 1; i < 6; ++i)
    {
        std::stringstream ss;
        ss << i;
        map98[i] = ss.str();
    }

    std::cout << "C++98  Output: ";
    std::map<int, std::string>::iterator map98Iter = map98.begin();
    while (map98Iter != map98.end())
    {
        std::cout << map98Iter->second;

        std::map<int, std::string>::iterator tempIter = map98Iter;
        ++map98Iter;
        map98.erase(tempIter);
    }
}

// In C++11, std::map::erase will return an iterator pointing to the next element located within the container
// Works for std::multimap::erase as well
void cpp11_mapErase()
{
    std::map<int, std::string> map11 {{1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}};

    std::cout << "C++11  Output: ";
    for (std::map<int, std::string>::iterator map11Iter = map11.begin(); map11Iter != map11.end(); map11Iter = map11.erase(map11Iter))
    {
        std::cout << map11Iter->second;
    }
}

// C++11 std::forward_list is a single-linked list instead of a double-linked list such as std::list
// A bucket will always be linked to the next bucket in a list but not to the bucket before it
void forwardLists()
{
    std::forward_list<int> forwardList {1, 2, 3, 4, 5};

    for (std::forward_list<int>::const_iterator a = forwardList.begin() ; a != forwardList.end() ; a++)
    {
        std::cout << *a << std::endl;
    }
}

// C++11 introduces unordered (multi)map and unorderd (multi)set
void hashTables()
{
    std::unordered_map<int, std::string> umap {{2, "2"}, {1, "1"}, {4, "4"}, {3, "3"}};

    for (std::pair<int, std::string> iter : umap)
    {
        std::cout << iter.first << " " << iter.second << std::endl;
    }
}

// Similar to vectors but has a defined size
void arrays()
{
    std::array<int, 5> arr {1, 2, 3, 4, 5};

    std::cout << sizeof(arr) << std::endl;
}