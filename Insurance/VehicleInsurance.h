#pragma once
#include "Insurance.h"

class VehicleInsurance : public insurance {
private:
    double engine_volume;

public:
    VehicleInsurance(int base_price, double engine_volume);
    ~VehicleInsurance() override;

    int calcFullPrice() const override;
    insurance* clone() const override;
    void printInfo() const override;
    void readFrom(std::istream& in) override;
    void writeTo(std::ostream& out) const override;
};