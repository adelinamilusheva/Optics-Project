#ifndef SUPPLIER_H
#define SUPPLIER_H
#include "Delivery.h"
#include "Optics.h"
#include <iostream>
#include <string>
#include <vector>

class Supplier
{
    friend std::ostream& operator<<(std::ostream& os, Supplier rhs);

private:
    std::string bulstat;
    std::string name;
    std::string location;
    std::string phoneNumber;
    Delivery deliveryPrice;
    std::vector<Optics> optics;

public:
    Supplier(std::string newBulstat,
        std::string newName,
        std::string newLocation,
        std::string newPhoneNumber,
        Delivery deliveryPrice,
        std::vector<Optics> newOptics);
    Supplier(const Supplier& source);
    Supplier();
    ~Supplier();
    std::string get_bulstat();
    void set_bulstat(std::string newBulstat);

    void set_name(std::string newName);
    std::string get_name();

    void set_location(std::string newLocation);
    std::string get_location();

    void set_phoneNumber(std::string newPhoneNumber);
    std::string get_phoneNumber();

    void set_delivery(double newDeliveryPrice);
    double get_delivery();

    std::vector<Optics> get_optics();

    void add_optics(Optics optics);
    void remove_optics(std::string serialNumber);
    
    void set_optics(std::vector<Optics>newOptics);
};

#endif // SUPPLIER_H
