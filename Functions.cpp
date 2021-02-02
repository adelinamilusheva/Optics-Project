#include "Delivery.h"
#include "Functions.h"
#include "Optics.h"
#include "Supplier.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void printAll(std::vector<Supplier>& suppliers)
{
    for(auto supplier : suppliers) {
        std::cout << supplier << std::endl;
    }
};

void printByName(std::vector<Supplier>& suppliers, std::string supplierName)
{
    bool match = false;
    for(auto supplier : suppliers) {
        if(supplier.get_name().compare(supplierName) == 0) {
            std::cout << supplier << std::endl;
            match = true;
        }
    }
    if(!match) {
        std::cout << "Such a supplier was not found.." << std::endl;
    }
};

void addSupplier(std::vector<Supplier>& suppliers, Supplier supplier)
{
    suppliers.push_back(supplier);
};

void makePurchase(std::vector<Supplier>& suppliers,
    std::vector<std::string> opticsSerialNumbers,
    std::string supplierName)
{
    bool isSupplier = false;
    bool validOptics = false;

    double price = 0;
    double deliveryPrice = 0;

    for(auto supplier : suppliers) {
        if(supplier.get_name().compare(supplierName) == 0) {
            for(auto number : opticsSerialNumbers) {
                validOptics = false;
                for(auto optics : supplier.get_optics()) {
                    if(number.compare(optics.get_serialNumber()) == 0) {
                        price += optics.get_price();
                        validOptics = true;
                    }
                }
                if(!validOptics) {
                    std::cout << "Invalid optics serial number..";
                    return;
                }
            }
            deliveryPrice = supplier.get_delivery();
            isSupplier = true;
        }
    }
    if(!isSupplier && !validOptics) {
        std::cout << "Invalid supplier.." << std::endl;
        return;
    }
    std::cout << "Price of optics: " << price << std::endl;
    std::cout << "Total price with delivery: " << deliveryPrice + price << std::endl;
};
void deleteSupplier(std::vector<Supplier>& suppliers, std::string supplierName) // tuka
{
    bool match = false;
    for(int i = 0; i < suppliers.size(); i++) { // tuka
        if(suppliers[i].get_name().compare(supplierName) == 0) {
            suppliers.erase(suppliers.begin() + i);
            match = true;
        }
    }
    if(match) {
        std::cout << "Successfull deleting of supplier.." << std::endl;
    } else {
        std::cout << "Invalid supplier.." << std::endl;
    }
};
void deleteOpticsFromSupplier(std::vector<Supplier>& suppliers, std::string serialNumber, std::string supplierName)
{
    bool match = false;
    for(auto supplier : suppliers) {
        if(supplier.get_name().compare(supplierName) == 0) {
            supplier.remove_optics(serialNumber);
            match = true;
        }
    }
    if(!match) {
        std::cout << "Invalid optics.." << std::endl;
    }
};

void saveInFile(std::vector<Supplier>& suppliers)
{
    std::ofstream writeToFile { "writeToFile.txt" };
    if(!writeToFile) {
        std::cerr << "Cant create file to write..." << std::endl;
        return;
    }

    for(Supplier supplier : suppliers) {
        writeToFile << supplier << std::endl;
    }
    writeToFile.close();
};
