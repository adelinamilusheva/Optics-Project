#include "Delivery.h"
#include "Optics.h"
#include "Supplier.h"
#include <iostream>
#include <string>
#include <vector>

Supplier::Supplier(std::string newBulstat,
    std::string newName,
    std::string newLocation,
    std::string newPhoneNumber,
    Delivery newDeliveryPrice,
    std::vector<Optics> newOptics)
{
    bulstat = newBulstat;
    name = newName;
    location = newLocation;
    phoneNumber = newPhoneNumber;
    deliveryPrice = newDeliveryPrice;
    optics = newOptics;
};
Supplier::Supplier() {};
Supplier::Supplier(const Supplier& source)
    : Supplier { source.bulstat, source.name, source.location, source.phoneNumber, source.deliveryPrice,
        source.optics } {
        // std::cout << "Supplier copy constructor called..." << std::endl;
    };

Supplier::~Supplier() {
    //  std::cout << "Supplier destructor called..." << std::endl;
};

std::string Supplier::get_bulstat()
{
    return bulstat;
};
void Supplier::set_bulstat(std::string newBulstat)
{
    bulstat = newBulstat;
};

void Supplier::set_name(std::string newName)
{
    name = newName;
};
std::string Supplier::get_name()
{
    return name;
};

void Supplier::set_location(std::string newLocation)
{
    location = newLocation;
};
std::string Supplier::get_location()
{
    return location;
};

void Supplier::set_phoneNumber(std::string newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
};
std::string Supplier::get_phoneNumber()
{
    return phoneNumber;
};
void Supplier::set_delivery(double newDeliveryPrice)
{
    deliveryPrice.set_deliveryPrice(newDeliveryPrice);
};
double Supplier::get_delivery()
{
    return deliveryPrice.get_deliveryPrice();
};
std::ostream& operator<<(std::ostream& os, Supplier rhs)
{
    os << "Supplier's bulstat: " << rhs.get_bulstat() << "; Supplier's name: " << rhs.get_name()
       << "; Supplier's location: " << rhs.get_location() << "; Supplier's phone number: " << rhs.get_phoneNumber()
       << "; Supplier's delivery price: " << rhs.get_delivery() << "; Optics serial numbers: ";
    for(auto optic : rhs.optics) {
        os << optic.get_serialNumber() << ", ";
    }
    return os;
};
std::vector<Optics> Supplier ::get_optics()
{
    return optics;
};
void Supplier ::add_optics(Optics newOptics)
{
    std::vector<Optics> currOptics = optics;
    currOptics.push_back(newOptics);
    set_optics(currOptics);
};
void Supplier ::remove_optics(std::string serialNumber)
{
    bool exist = false;
    for(int i = 0; i < optics.size(); i++) { 
        if(optics[i].get_serialNumber().compare(serialNumber) == 0) {
            optics.erase(optics.begin() + i);
            exist = true;
        }
    }
    if(exist) {
        set_optics(optics);
        std::cout << "Successfull deleting optics with serial number: " << serialNumber << std::endl;
    } else {
        std::cout << "Not found optics with serial number: " << serialNumber << std::endl;
    }
};
void Supplier::set_optics(std::vector<Optics> newOptics)
{
    optics = newOptics;
};