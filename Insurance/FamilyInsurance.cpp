#include "FamilyInsurance.h"

FamilyInsurance::FamilyInsurance() : insurance(100), family_members(3) {}

FamilyInsurance::FamilyInsurance(int family_members, int base_price)
    : insurance(base_price), family_members(family_members) {}

FamilyInsurance::FamilyInsurance(const FamilyInsurance& i) : insurance(i), family_members(i.family_members) {}

int FamilyInsurance::calcFullPrice() const {
    return getPrice() * family_members;
}

insurance* FamilyInsurance::clone() const {
    return new FamilyInsurance(*this);
}

void FamilyInsurance::printInfo() const {
    std::cout << "Family insurance, Family members: " << family_members << ". Total price: " << calcFullPrice() << std::endl;
}

void FamilyInsurance::readFrom(std::istream& in) {
    in >> family_members;
}

void FamilyInsurance::writeTo(std::ostream& out) const {
    out << family_members;
}

