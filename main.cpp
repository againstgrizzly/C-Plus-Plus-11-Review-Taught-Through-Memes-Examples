#include <iostream>
#include <vector>
#include <sstream>

#include "Dog.hpp"
#include "Car.hpp"

using namespace std;

void LambdaFunctionsExamples();

int main()
{

    LambdaFunctionsExamples();

    return 0;
}

///
void LambdaFunctionsExamples()
{
    // A lambda expression, sometimes also referred to as a lambda function
    // is a simplified notation for defining and using an anonymous
    // function object (The C++ Programming Language 11.4)

    // Oversimplified, it's a way to write reusable functions within functions
    // Negates polluting a class with a function that's repeatedly called
    // in only one function.

    // Syntax [captures](parameters) -> optionalReturnType { statements }

    /******************/
    /***** Basics *****/
    /******************/

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
     
    /********************/
    /***** Captures *****/
    /********************/

    // We've so far only looked at lambdas that do not need data outside of what
    // is passed as parameters, but what if we want to use variables that are
    // outside the scope of the lambda. In such a case, "captures" are needed

    // Default:         []       Disallows use of variables outside the scope of the lambda expression
    // Copy:            [=]      Capture-by-copy variables outside of scope
    // Reference:       [&]      Capture-by-reference variables outside of scope
    // SingleVarByCopy: [myVar]  Capture single var outside of scope by value
    // SingleVarByRef:  [&myVar] Capture single var outside of scope by reference
    // CaptureList:     [capture-list]

    // Default example
    auto divide = [/*Default*/](const double inFirstParam, const double inSecondParam)
    {
        return inFirstParam / inSecondParam;
    };

    std::cout << "1 / 2 = " << divide(1, 2) << std::endl << std::endl;

    // Copy Example
    Car aCar("Hyundai", "Civic", 100);

    auto captureByValue = [=](/* No parameters passed */)
    {
        std::cout << aCar.make << " " << aCar.model << " captured by value" << std::endl << std::endl;
    };

    // Call the lambda function
    captureByValue();

    // Reference example
    auto captureByReference = [&](/* No parameters passed */)
    {
        std::cout << aCar.make << " " << aCar.model << " captured by reference" << std::endl << std::endl;
        //Alter referenced value
        aCar.model = "Sonata";
    };

    // Call the lambda function
    captureByReference();

    std::cout << aCar.make << " " << aCar.model << " captured by reference and altered" << std::endl << std::endl;

    /*************************/
    /***** Capture lists *****/
    /*************************/

    //
}

// void SwapsAndDerivatives()
// {

// }

void RawStringLiteral()
{
    string normalString;
}
