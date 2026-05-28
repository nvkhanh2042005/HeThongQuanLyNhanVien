#include "ProductionEmployee.h"
#include <iomanip>
#include <sstream>

ProductionEmployee::ProductionEmployee() : Employee() {
    productQuantity = 0;
    productPrice = 0;
}

ProductionEmployee::ProductionEmployee(string id, string name, string department, double baseSalary,
                                       int productQuantity, double productPrice)
    : Employee(id, name, department, baseSalary) {
    this->productQuantity = productQuantity;
    this->productPrice = productPrice;
}

double ProductionEmployee::calculateSalary() const {
    return baseSalary + productQuantity * productPrice;
}

string ProductionEmployee::getType() const {
    return "Production";
}

string ProductionEmployee::toFileString() const {
    stringstream ss;
    ss << "PRODUCTION," << id << "," << name << "," << department << ","
       << baseSalary << "," << productQuantity << "," << productPrice;
    return ss.str();
}

void ProductionEmployee::input() {
    Employee::input();

    cout << "Enter product quantity: ";
    cin >> productQuantity;

    cout << "Enter product price: ";
    cin >> productPrice;
    cin.ignore();
}

void ProductionEmployee::display() const {
    Employee::display();
    cout << left
         << setw(15) << productQuantity
         << setw(18) << fixed << setprecision(0) << productPrice
         << setw(15) << fixed << setprecision(0) << calculateSalary()
         << setw(12) << getType()
         << endl;
}
