#include <iostream>
#include <vector>
#include <sstream>
#include <functional> // Include to use lambda expressions
#include <math.h>

#include "Dog.hpp"
#include "Car.hpp"
#include "Containers.hpp"

void LambdaFunctionExamples();

int main()
{
    // LambdaFunctionExamples();

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

    // Fun fact: Lambda-calculus was the first object-oriented
    // language (1932) - William Cook, "On Understanding Data Abstraction, Revisited"

    // Syntax: [](){}
    // [] capture
    // () arguments (params)
    // {} lambda implementation (function meat)

    /**********************************************************/
    /************************* Basics *************************/
    /**********************************************************/

    // This is a valid lambda expression!
    // [](){}; /* Commented out to prevent compiler warnings */

    // a simple lambda (that automatically calls itself)
    [](int val){
        std::cout << val << std::endl << std::endl;
    }(100);

    // Lambda functions need not be called in-place. In almost all cases
    // it's better store them in a function pointer so they can be called
    // wherever. New are C++11 style function pointers. No need to make typdefs
    // or use native syntax
    std::function<int(int, int)> add = [](int inFirstParam, int inSecondParam) {
        return inFirstParam + inSecondParam;
    };

    std::cout << "1 + 2 = " << add(1, 2) << std::endl;

    // When creating custom lambda functions,
    auto subtract = [](int inFirstParam, int inSecondParam) {
        return inFirstParam - inSecondParam;
    };

    std::vector<std::function<int(int, int)>> functionVector = {add, subtract};
    for (auto aFunction : functionVector)
    {
        std::cout << aFunction(2, 3) << std::endl;
    }
    std::cout << "5 - 6 = " << subtract(5, 6) << std::endl;

    // You can optionally declare a return type
    auto truncatedMultiply = [](double inFirstParam, double inSecondParam) -> int {
        return inFirstParam * inSecondParam;
    };

    std::cout << "5.5 * 6.3 = " << truncatedMultiply(5.5, 6.3) << std::endl
         << std::endl;

    // Parameters can be made const and be passed by reference and behave as you would expect

    // Example
    //        Make,      Model,        Top Speed MPH
    Car myCar("Ferrari", "458 Italia", 202);

    // Notice that the car is being altered via reference
    auto carUpdate = [](Car &outCar, const std::string &inMake, const std::string &inModel, const int inTopSpeedMPH) {
        outCar.make        = inMake;
        outCar.model       = inModel;
        outCar.topSpeedMPH = inTopSpeedMPH;
    };

    // Before
    std::cout << "Before Update:\n\t" << myCar.to_string() << std::endl
         << std::endl;

    // Update the car via reference
    carUpdate(myCar, "Toyota", "Corolla", 90);

    // After
    std::cout << "After Update:\n\t" << myCar.to_string() << std::endl
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
        std::cout << myString << std::endl;
    };
    captureByValue();

    // Reference example
    auto captureByReference = [&](/* No parameters passed */)
    {
        myString = "Reference Example: Captured by reference and altered";
    };
    captureByReference(); // Updates myString via reference

    std::cout << myString << std::endl;

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

    /**********************************************************/
    /***************** Functional Programming *****************/
    /**********************************************************/

    // Functional programming is all about writing the program functions
    // similar to a mathematical fucntion
    // ex. f(x) = x * x;
    //     f(5) = 25
    //     f(x, y) = x^2 + y^2
    //     f(2, 5) = 29

    // OO makes code understandable by encapsulating moving
    // parts. Functional programming makes code understandable by minimizing
    // moving parts. - Michael Feathers

    // No matter what language you work in, programming in a functional style provides
    // benefits. You should do it whenever it is convenienet and you should think hard
    // about the decision when it isn't convenient - John Carmack

    auto quadraticFormula = [](double a, double b, double c) -> std::pair<double, double> {
        double x1 = [](double a, double b, double c){ return (-b + sqrt(pow(b, 2) - 4*a*c)) / (2 * a); }(a, b, c);
        double x2 = [](double a, double b, double c){ return (-b - sqrt(pow(b, 2) - 4*a*c)) / (2 * a); }(a, b, c);
        return std::make_pair(x1, x2);
    };

    // x^2 + x - 1
    std::pair<double, double> result = quadraticFormula(1, 1, -1);
    std::cout << result.first << ", " << result.second << std::endl;
}