#ifndef OFFICE_EMPLOYEE_H
#define OFFICE_EMPLOYEE_H

#include "Employee.h"

class OfficeEmployee : public Employee {
private:
    int workingDays;
    double allowancePerDay;

public:
    OfficeEmployee();
    OfficeEmployee(string id, string name, string department, double baseSalary,
                   int workingDays, double allowancePerDay);

    double calculateSalary() const override;
    string getType() const override;
    string toFileString() const override;

    void input() override;
    void display() const override;
};

#endif
