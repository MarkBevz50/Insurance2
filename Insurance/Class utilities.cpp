#include "Class utilities.h"
void readInsuranceFromFile(const std::string& filename, insurance** insurances, size_t size)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    char insuranceType;
    for (size_t i = 0; i < size; ++i)
    {
        file >> insuranceType;

        insurance* prototype = nullptr;

        if (insuranceType == FamilyInsurance::FAMILY_TYPE)
        {
            prototype = new FamilyInsurance();
        }
        else if (insuranceType == VehicleInsurance::VEHICLE_TYPE)
        {
            prototype = new VehicleInsurance();
        }

        if (prototype)
        {
            insurances[i] = prototype->clone();
            insurances[i]->readFrom(file);
            delete prototype;
        }
    }

    file.close();
}
void printInsurances(const insurance** insurances, size_t size)
{
    std::cout << "List of Insurances:" << std::endl;
    for (size_t i = 0; i < size; ++i)
    {
        insurances[i]->printInfo();
    }
    std::cout << std::endl;
}

int calculateTotalPrice(const insurance** insurances, size_t size)
{
    int totalCost = 0;
    for (size_t i = 0; i < size; ++i)
    {
        totalCost += insurances[i]->calcFullPrice();
    }
    return totalCost;
}

const insurance* findMostExpensive(const insurance** insurances, size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    const insurance* mostExpensive = insurances[0];

    for (size_t i = 1; i < size; ++i)
    {
        if (*insurances[i] < *mostExpensive)
        {
            mostExpensive = insurances[i];
        }
    }

    return mostExpensive;
}

const insurance* findCheapest(const insurance** insurances, size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    const insurance* cheapest = insurances[0];

    for (size_t i = 1; i < size; ++i)
    {
        if (*insurances[i] < *cheapest)
        {
            cheapest = insurances[i];
        }
    }

    return cheapest;
}
