#pragma once
#include "Insurance.h"

class FamilyInsurance : public insurance
{
private:

	int family_members;
public:
	FamilyInsurance();
	FamilyInsurance(int family_members, int base_price);
	FamilyInsurance(const FamilyInsurance& i);
	int calcFullPrice() const override;
	insurance* clone() const override;
	void printInfo()const override;
	void readFrom(std::istream& in) override;
	void writeTo(std::ostream& out) const override;
};