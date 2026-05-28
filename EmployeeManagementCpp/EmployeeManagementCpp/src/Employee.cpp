#include "Employee.h"
#include <iomanip>

Employee::Employee() {
    id = "";
    name = "";
    department = "";
    baseSalary = 0;
}

Employee::Employee(string id, string name, string department, double baseSalary) {
    this->id = id;
    this->name = name;
    this->department = department;
    this->baseSalary = baseSalary;
}

Employee::~Employee() {}

string Employee::getId() const {
    return id;
}

string Employee::getName() const {
    return name;
}

string Employee::getDepartment() const {
    return department;
}

double Employee::getBaseSalary() const {
    return baseSalary;
}

void Employee::setName(string name) {
    this->name = name;
}

void Employee::setDepartment(string department) {
    this->department = department;
}

void Employee::setBaseSalary(double baseSalary) {
    this->baseSalary = baseSalary;
}

void Employee::input() {
    cout << "Enter employee ID: ";
    getline(cin, id);

    cout << "Enter employee name: ";
    getline(cin, name);

    cout << "Enter department: ";
    getline(cin, department);

    cout << "Enter base salary: ";
    cin >> baseSalary;
    cin.ignore();
}

void Employee::display() const {
    cout << left
         << setw(12) << id
         << setw(25) << name
         << setw(18) << department
         << setw(15) << fixed << setprecision(0) << baseSalary;
}
