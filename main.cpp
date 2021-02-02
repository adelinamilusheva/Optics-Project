#include "Delivery.h"
#include "Functions.h"
#include "Optics.h"
#include "Supplier.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void showOptions(std::vector<Supplier> suppliers);

int main()
{

    std::ifstream readFromFIle;
    readFromFIle.open("fileToRead.txt");

    if(!readFromFIle) {
        std::cerr << "Cannot open the file to read...." << std::endl;
        return 1;
    }
    // std::cout << "Reading from file.." << std::endl;
    std::vector<Supplier> suppliers;
    std::string bulstatVal;
    std::string nameVal;
    std::string locationVal;
    std::string phoneNumberVal;
    Delivery deliveryPriceV {};
    double deliveryPriceVal;
    int countOfOptics;
    std::string serialNumberVal;
    std::string typeVal;
    double widthVal;
    double diopterVal;
    double priceVal;
    std::string materialVal;
    std::vector<Optics> optics;

    while(!readFromFIle.eof()) {

        readFromFIle >> bulstatVal >> nameVal >> locationVal >> phoneNumberVal >> deliveryPriceVal >> countOfOptics;
        deliveryPriceV.set_deliveryPrice(deliveryPriceVal);
        for(int i = 0; i < countOfOptics; i++) {
            readFromFIle >> serialNumberVal >> typeVal >> widthVal >> diopterVal >> priceVal >> materialVal;
            Optics optic = { serialNumberVal, typeVal, widthVal, diopterVal, priceVal, materialVal };
            optics.push_back(optic);
        }
        Supplier supplier = { bulstatVal, nameVal, locationVal, phoneNumberVal, deliveryPriceV, optics };
        suppliers.push_back(supplier);
    }

    showOptions(suppliers);
    readFromFIle.close();
    return 0;
}

void showOptions(std::vector<Supplier> suppliers)
{
    bool start = true;
    int option;
    std::string bulstatOfSupplier;
    std::string nameOfSupplier;
    std::string locationOfSupplier;
    std::string phoneNumberOfSupplier;
    Delivery deliveryOfSupplier;
    double deliveryPriceOfSupplier;
    Optics opticsOfSupplier;
    std::string serialNumberOfOptics;
    std::string typeOfOptics;
    double widthOfOptics;
    double diopterOfOptics;
    double priceOfOptics;
    std::string materialOfOptics;
    Supplier supplier;
    std::vector<std::string> serialNumbers;
    int countSerialNumbers;
    bool addOrNot = false;
    int numberOfOptics;
    std::vector<Optics> addOptics;

    while(start) {
        std::cout << "*******Menu*******" << std::endl;
        std::cout << "Press: " << std::endl;
        std::cout << "1. To print all suppliers" << std::endl;
        std::cout << "2. To print a supplier by name" << std::endl;
        std::cout << "3. To add a supplier and optics to him" << std::endl;
        std::cout << "4. To choose a supplier to buy optics from" << std::endl;
        std::cout << "5. To delete a supplier" << std::endl;
        std::cout << "6. To delete optics from a supplier" << std::endl;
        std::cout << "7. To quit and save in a file" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> option;
        switch(option) {
        case 1:
            printAll(suppliers);
            break;
        case 2:
            std::cout << "Enter a name for a supplier: " << std::endl;
            std::cin >> nameOfSupplier;
            printByName(suppliers, nameOfSupplier);
            break;
        case 3:
            std::cout << "Enter a bulstat for a supplier: " << std::endl;
            std::cin >> bulstatOfSupplier;
            std::cout << "Enter a name for a supplier: " << std::endl;
            std::cin >> nameOfSupplier;
            std::cout << "Enter a location for a supplier: " << std::endl;
            std::cin >> locationOfSupplier;
            std::cout << "Enter a phone number for a supplier: " << std::endl;
            std::cin >> phoneNumberOfSupplier;
            std::cout << "Enter delivery price of the supplier: " << std::endl;
            std::cin >> deliveryPriceOfSupplier;
            std::cout << "If u want to add optics to the supplier type '1', if not type '0' " << std::endl;
            std::cin >> addOrNot;
            if(addOrNot) {
                std::cout << "Enter number of optics that you want to add: " << std::endl;
                std::cin >> numberOfOptics;
                for(int i = 0; i < numberOfOptics; i++) {
                    std::cout << "Enter a serial number for optics: " << std::endl;
                    std::cin >> serialNumberOfOptics;
                    std::cout << "Enter a type for optics: " << std::endl;
                    std::cin >> typeOfOptics;
                    std::cout << "Enter width for optics: " << std::endl;
                    std::cin >> widthOfOptics;
                    std::cout << "Enter diopters for optics: " << std::endl;
                    std::cin >> diopterOfOptics;
                    std::cout << "Enter price for optics: " << std::endl;
                    std::cin >> priceOfOptics;
                    std::cout << "Enter material for optics: " << std::endl;
                    std::cin >> materialOfOptics;

                    opticsOfSupplier.set_serialNumber(serialNumberOfOptics);
                    opticsOfSupplier.set_type(typeOfOptics);
                    opticsOfSupplier.set_width(widthOfOptics);
                    opticsOfSupplier.set_diopter(diopterOfOptics);
                    opticsOfSupplier.set_price(priceOfOptics);
                    opticsOfSupplier.set_material(materialOfOptics);
                    addOptics.push_back(opticsOfSupplier);
                }
            }
            supplier.set_bulstat(bulstatOfSupplier);
            supplier.set_name(nameOfSupplier);
            supplier.set_location(locationOfSupplier);
            supplier.set_phoneNumber(phoneNumberOfSupplier);
            supplier.set_delivery(deliveryPriceOfSupplier);
            supplier.set_optics(addOptics);
            addSupplier(suppliers, supplier);
            break;
        case 4:
            std::cout << "Enter number of serial numbers: " << std::endl;
            std::cin >> countSerialNumbers;
            for(int i = 0; i < countSerialNumbers; i++) {
                std::cout << "Enter serial number: " << std::endl;
                std::cin >> serialNumberOfOptics;
                serialNumbers.push_back(serialNumberOfOptics);
            }
            std::cout << "Enter a name for a supplier: " << std::endl;
            std::cin >> nameOfSupplier;
            makePurchase(suppliers, serialNumbers, nameOfSupplier);
            break;
        case 5:
            std::cout << "Enter a name for a supplier: " << std::endl;
            std::cin >> nameOfSupplier;
            deleteSupplier(suppliers, nameOfSupplier);
            break;
        case 6:
            std::cout << "Enter serial number of optics: " << std::endl;
            std::cin >> serialNumberOfOptics;
            std::cout << "Enter a name for a supplier: " << std::endl;
            std::cin >> nameOfSupplier;
            deleteOpticsFromSupplier(suppliers, serialNumberOfOptics, nameOfSupplier);
            break;
        case 7:
            saveInFile(suppliers);
            start = false;
            break;
        default:
            std::cout << "Invalid input! Try again...." << std::endl;
            break;
        }
    }
}