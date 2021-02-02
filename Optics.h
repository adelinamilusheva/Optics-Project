#ifndef OPTICS_H
#define OPTICS_H
#include <iostream>
#include <string>

class Optics
{
private:
    std::string serialNumber;
    std::string type;
    double width;
    double diopter;
    double price;
    std::string material;

public:
    Optics(std::string serialNumber,
        std::string newType,
        double newWidth,
        double newDiopter,
        double newPrice,
        std::string newMaterial);
    Optics(const Optics& source);
    Optics();
    ~Optics();

    std::string get_serialNumber();
    void set_serialNumber(std::string serialNumber);
    std::string get_type();
    void set_type(std::string newType);
    double get_width();
    void set_width(double newWidth);
    double get_diopter();
    void set_diopter(double newDiopter);
    double get_price();
    void set_price(double newPrice);
    std::string get_material();
    void set_material(std::string newMaterial);
};

#endif // OPTICS_H
