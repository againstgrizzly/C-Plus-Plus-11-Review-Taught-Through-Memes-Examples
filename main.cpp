#include <iostream>
#include <vector>
#include <sstream>

#include "Dog.hpp"
#include "Car.hpp"

using namespace std;

void LambdaFunctionExamples();

int main()
{

    LambdaFunctionExamples();

    return 0;
}

void LambdaFunctionExamples()
{
    // A lambda expression, sometimes also referred to as a lambda function
    // is a simplified notation for defining and using an anonymous
    // function object (The C++ Programming Language 11.4)

    // Oversimplified, it's a way to write reusable functions within functions
    // Negates polluting a class with a function that's repeatedly called
    // in only one function.

    // Syntax [captures](parameters) -> optionalReturnType { statements }

    /**********************************************************/
    /************************* Basics *************************/
    /**********************************************************/

    // a simple lambda
    function<int(int, int)> add = [](int inFirstParam, int inSecondParam) {
        return inFirstParam + inSecondParam;
    };

    cout << "1 + 2 = " << add(1, 2) << endl
         << endl;

    // When creating custom lambda functions, it's way better to just use auto
    // as the return type
    auto subtract = [](int inFirstParam, int inSecondParam) {
        return inFirstParam - inSecondParam;
    };

    cout << "5 - 6 = " << subtract(5, 6) << endl
         << endl;

    // You can optionally declare a return type
    auto truncatedMultiply = [](double inFirstParam, double inSecondParam) -> int {
        return inFirstParam * inSecondParam;
    };

    cout << "5.5 * 6.3 = " << truncatedMultiply(5.5, 6.3) << endl
         << endl;

    // Parameters can be made const and be passed by reference and behave as you would expect

    // Example
    //        Make,      Model,        Top Speed MPH
    Car myCar("Ferrari", "458 Italia", 202);

    // Notice that the car is being altered via reference
    auto carUpdate = [](Car &outCar, const string &inMake, const string &inModel, const int inTopSpeedMPH) {
        outCar.make        = inMake;
        outCar.model       = inModel;
        outCar.topSpeedMPH = inTopSpeedMPH;
    };

    // Before
    cout << "Before Update:\n\t" << myCar.to_string() << endl
         << std::endl;

    // Update the car via reference
    carUpdate(myCar, "Toyota", "Corolla", 90);

    // After
    cout << "After Update:\n\t" << myCar.to_string() << endl
         << std::endl;
     
    /**********************************************************************/
    /****************************** Captures ******************************/
    /**********************************************************************/

    // So far only looked at lambdas that do not need data outside of what
    // is passed as parameters, but what if we want to use variables that are
    // outside the scope of the lambda. In such a case, "captures" are needed

    // Default:         []                 Disallows use of variables outside the scope of the lambda expression
    // Copy:            [=]                Capture-by-copy variables outside of scope (including members)
    // Reference:       [&]                Capture-by-reference variables outside of scope (including members)
    // ValCaptureList:  [capture-list]     Explicit capture; List of local variables to be captured by value
    // RefCaptureList:  [&capture-list]    Explicit capture; List of local variables to be captured by value
    // Ref,DontCapture: [&, capture-list]  Capture all local variables by reference EXCEPT those in capture list (example not provided)
    // Val,DontCapture: [=, capture-list]  Capture all local variables by value EXCEPT those in capture list (example not provided)

    // Default example
    auto defaultExample = [/*Default*/]()
    {
        std::cout << " Default example: Cannot capture variables outside scope" << std::endl << std::endl;
    };
    defaultExample();

    // Copy Example
    std::string myString = "Copy example: Captured by value";
    auto captureByValue = [=](/* No parameters passed */)
    {
        // This is a copy
        std::cout << myString << std::endl << std::endl;
    };
    captureByValue();

    // Reference example
    auto captureByReference = [&](/* No parameters passed */)
    {
        myString = "Reference Example: Captured by reference and altered";
    };
    captureByReference(); // Updates myString via reference

    std::cout << myString << std::endl << std::endl;

    // Capture local variables by value
    std::string myString1("value 1"), myString2("value 2");
    auto valueCaptureListExample = [myString1, myString2]()
    {
        std::cout << "Captured via val capture list: " << myString1 << " " << myString2 << std::endl << std::endl;
    };
    valueCaptureListExample();

    // Capture local variables by reference and alter them
    auto referenceCaptureListExample = [&myString1, &myString2]()
    {
        myString1 = "Altered value 1";
        myString2 = "Altered value 2";
    };
    referenceCaptureListExample();
    std::cout << "Captured and altered via reference capture list: " << myString1 << " " << myString2 << std::endl << std::endl;
}