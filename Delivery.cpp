#include "Delivery.h"
#include <iostream>
#include <string>

Delivery::Delivery(double newDeliveryPrice)
{
    deliveryPrice = newDeliveryPrice;
};
Delivery::Delivery(const Delivery& source)
    : Delivery { source.deliveryPrice }
{
    //std::cout << "Delivery copy constructor called..." << std::endl;
};
Delivery::Delivery()
    : Delivery { 10 } {

    };
Delivery::~Delivery()
{
    //std::cout << "Delivery destructor called..." << std::endl;
};

double Delivery::get_deliveryPrice()
{
    return deliveryPrice;
};
void Delivery::set_deliveryPrice(double newDeliveryPrice)
{
    deliveryPrice = newDeliveryPrice;
};