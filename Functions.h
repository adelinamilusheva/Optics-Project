#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Delivery.h"
#include "Optics.h"
#include "Supplier.h"
#include <iostream>
#include <string>
#include <vector>

void printAll(std::vector<Supplier>& suppliers);
void printByName(std::vector<Supplier>& suppliers, std::string supplierName);
void addSupplier(std::vector<Supplier>& suppliers, Supplier suplier);
void makePurchase(std::vector<Supplier>& suppliers, std::vector<std::string> opticsSerialNumbers, std::string supplierName);
void deleteSupplier(std::vector<Supplier>& suppliers, std::string supplierName);
void deleteOpticsFromSupplier(std::vector<Supplier>& suppliers, std::string serialNumber, std::string supplierName);
void saveInFile(std::vector<Supplier>&suppliers);

#endif // FUNCTIONS_H
