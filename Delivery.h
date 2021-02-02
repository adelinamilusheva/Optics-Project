#ifndef DELIVERY_H
#define DELIVERY_H
#include <iostream>
#include <string>

class Delivery
{
private:
    double deliveryPrice;

public:
    Delivery(double newDeliveryPrice);
    Delivery(const Delivery& source);
    Delivery();
    ~Delivery();

    double get_deliveryPrice();
    void set_deliveryPrice(double newDeliveryPrice);
};

#endif // DELIVERY_H
