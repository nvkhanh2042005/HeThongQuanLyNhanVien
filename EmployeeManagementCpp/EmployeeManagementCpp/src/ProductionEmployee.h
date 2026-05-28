#ifndef PRODUCTION_EMPLOYEE_H
#define PRODUCTION_EMPLOYEE_H

#include "Employee.h"

class ProductionEmployee : public Employee {
private:
    int productQuantity;
    double productPrice;

public:
    ProductionEmployee();
    ProductionEmployee(string id, string name, string department, double baseSalary,
                       int productQuantity, double productPrice);

    double calculateSalary() const override;
    string getType() const override;
    string toFileString() const override;

    void input() override;
    void display() const override;
};

#endif
