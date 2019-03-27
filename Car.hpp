#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Car
{
  public:
    Car(/* Default Constructor */) : make(""), model(""), topSpeedMPH(0) {}
    Car(const string &inMake, const string &inModel, const int inTopSpeedMPH) : make(inMake), model(inModel), topSpeedMPH(inTopSpeedMPH) {}
    ~Car() {}

    string to_string()
    {
        stringstream message;
        message << "Make: " << make << ", Model: " << model << ", Speed: " << topSpeedMPH;
        return message.str();
    }

    string make, model;
    int topSpeedMPH;
};