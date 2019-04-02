#include <string>
#include <sstream>
#include <iostream>

class Car
{
  public:
    Car(/* Default Constructor */) : make(""), model(""), topSpeedMPH(0) {}
    Car(const std::string &inMake, const std::string &inModel, const int inTopSpeedMPH) : make(inMake), model(inModel), topSpeedMPH(inTopSpeedMPH) {}
    ~Car() {}

    std::string to_string()
    {
        std::stringstream message;
        message << "Make: " << make << ", Model: " << model << ", Speed: " << topSpeedMPH;
        return message.str();
    }

    std::string make, model;
    int topSpeedMPH;
};