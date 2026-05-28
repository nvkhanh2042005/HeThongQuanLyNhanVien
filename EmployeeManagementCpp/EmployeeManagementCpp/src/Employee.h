#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string id;
    string name;
    string department;
    double baseSalary;

public:
    Employee();
    Employee(string id, string name, string department, double baseSalary);
    virtual ~Employee();

    string getId() const;
    string getName() const;
    string getDepartment() const;
    double getBaseSalary() const;

    void setName(string name);
    void setDepartment(string department);
    void setBaseSalary(double baseSalary);

    virtual double calculateSalary() const = 0;
    virtual string getType() const = 0;
    virtual string toFileString() const = 0;

    virtual void input();
    virtual void display() const;
};

#endif
