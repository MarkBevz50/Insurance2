#include "VehicleInsurance.h"

VehicleInsurance::VehicleInsurance(int base_price, double engine_volume)
    : insurance(base_price), engine_volume(engine_volume) {}

VehicleInsurance::~VehicleInsurance() {}

int VehicleInsurance::calcFullPrice() const {
    double additionalCost = 0.0;

    if (engine_volume > 2.0) {
        additionalCost += getPrice() * 0.15;
    }

    if (engine_volume > 3.0) {
        additionalCost += getPrice() * 0.25;
    }

    return static_cast<int>(getPrice() + additionalCost);
}
insurance* VehicleInsurance::clone() const {
    return new VehicleInsurance(*this);
}

void VehicleInsurance::printInfo() const {
    std::cout << "Vehicle insurance, Engine volume: " << engine_volume << ". Total price: " << calcFullPrice() << std::endl;
}

void VehicleInsurance::readFrom(std::istream& in) {
    
    in >> engine_volume;
}

void VehicleInsurance::writeTo(std::ostream& out) const {
   
    out << engine_volume;
}