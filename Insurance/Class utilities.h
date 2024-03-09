#pragma once
#include "Insurance.h"
#include "FamilyInsurance.h"
#include "VehicleInsurance.h"
void readInsuranceFromFile(const std::string& filename, insurance** insurances, size_t size);
void printInsurances( insurance** insurances, size_t size);
int calculateTotalPrice( insurance** insurances, size_t size);
const insurance* findMostExpensive(const insurance** insurances, size_t size);
const insurance* findCheapest(const insurance** insurances, size_t size);