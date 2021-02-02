#include "Optics.h"
#include <iostream>
#include <string>

Optics::Optics(std::string newSerialNumber,
    std::string newType,
    double newWidth,
    double newDiopter,
    double newPrice,
    std::string newMaterial)
{
    serialNumber = newSerialNumber;
    type = newType;
    width = newWidth;
    diopter = newDiopter;
    price = newPrice;
    material = newMaterial;
};
Optics::Optics() {};
Optics::Optics(const Optics& source)
    : Optics { source.serialNumber, source.type, source.width, source.diopter, source.price, source.material }
{
    //std::cout << "Optics copy constructor called..." << std::endl;
};
Optics::~Optics()
{
    //std::cout << "Optics destructor called..." << std::endl;
};

std::string Optics::get_serialNumber()
{
    return serialNumber;
};
void Optics::set_serialNumber(std::string newSerialNumber)
{
    serialNumber = newSerialNumber;
};
std::string Optics::get_type()
{
    return type;
};
void Optics::set_type(std::string newType)
{
    type = newType;
};
double Optics::get_width()
{
    return width;
};
void Optics::set_width(double newWidth)
{
    width = newWidth;
};
double Optics::get_diopter()
{
    return diopter;
};
void Optics::set_diopter(double newDiopter)
{
    diopter = newDiopter;
};
double Optics::get_price()
{
    return price;
};
void Optics::set_price(double newPrice)
{
    price = newPrice;
};
std::string Optics::get_material()
{
    return material;
};
void Optics::set_material(std::string newMaterial)
{
    material = newMaterial;
};