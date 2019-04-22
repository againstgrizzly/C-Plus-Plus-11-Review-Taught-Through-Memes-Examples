class RangeBasedForLoops
{
    public:
        RangeBasedForLoops()
        {
            // Range-based for loop in C++ executes for a loop
            // over a range. Used as a more readable equivalent to
            // the traditional for loop
        
            // Instead of indexing or iterating over a container
            // use a range based for loop
        
            // Example: index based to range based
            std::vector<std::string> nameVector = {"Bobby", "Julie", "Kaiba", "Yugi", "Joey"};
        
            // Index based
            for (unsigned int i = 0; i < nameVector.size(); ++i)
            {
                std::cout << nameVector[i] << std::endl;
            }
        
            // Iterator based
            for (std::vector<std::string>::const_iterator nameVectorIterator = nameVector.begin(); nameVectorIterator != nameVector.end(); ++nameVectorIterator)
            {
                std::cout << *nameVectorIterator << std::endl;
            }
        
            // Range-based way
            for (const std::string& name : nameVector)
            {
                std::cout << name << std::endl;
            }
        
            // Each element of a range based for loop can be obtained by
            // value and reference and also they can be made const
            // In most circumstances, it is best to obtain values
            // by const reference. When obtaining values by non const reference
            // they can be altered by reference as you would expect
        
            // By value (Bad in most cases)
            for (const std::string name : nameVector)
            {
                std::cout << name << std::endl;
            }
        
            // By reference (Better in most cases)
            for (const std::string &name : nameVector)
            {
                std::cout << name << std::endl;
            }
        
            // Range based for loops work with any container
            // (i.e. have "begin" and "end" functions)
            // This includes vectors, C++11 arrays, maps, sets, lists, etc.
        
            // Example: Range based for loop with map
        
            std::map<int, std::string> idPersonMap = {
                {1, "Ash"},
                {2, "Brock"},
                {3, "Misty"}
            };
        
            // This monstrosity
            for (std::map<int, std::string>::const_iterator idPersonMapIter = idPersonMap.begin(); idPersonMapIter != idPersonMap.end(); ++idPersonMapIter)
            {
                std::cout << "<" << idPersonMapIter->first << ", " << idPersonMapIter->second << ">" << std::endl;
            }
        
            // Becomes this
            for (const std::pair<int, std::string> &idPersonPair : idPersonMap)
            {
                std::cout << "<" << idPersonPair.first << ", " << idPersonPair.second << ">" << std::endl;
            }
        
            // Can even become this
            for (const auto &idPersonPair : idPersonMap)
            {
                std::cout << "<" << idPersonPair.first << ", " << idPersonPair.second << ">" << std::endl;
            }
        }    
};