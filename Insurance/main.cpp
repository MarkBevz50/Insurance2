#include <iostream>
#include "Insurance.h"
#include "FamilyInsurance.h"
#include "VehicleInsurance.h"
int main()
{
	FamilyInsurance A(4, 2500);
	A.printInfo();
	VehicleInsurance B(120, 12);
	B.printInfo();
	return 0;




}