#include "OfficeEmployee.h"
#include <iomanip>
#include <sstream>

OfficeEmployee::OfficeEmployee() : Employee() {
    workingDays = 0;
    allowancePerDay = 0;
}

OfficeEmployee::OfficeEmployee(string id, string name, string department, double baseSalary,
                               int workingDays, double allowancePerDay)
    : Employee(id, name, department, baseSalary) {
    this->workingDays = workingDays;
    this->allowancePerDay = allowancePerDay;
}

double OfficeEmployee::calculateSalary() const {
    return baseSalary + workingDays * allowancePerDay;
}

string OfficeEmployee::getType() const {
    return "Office";
}

string OfficeEmployee::toFileString() const {
    stringstream ss;
    ss << "OFFICE," << id << "," << name << "," << department << ","
       << baseSalary << "," << workingDays << "," << allowancePerDay;
    return ss.str();
}

void OfficeEmployee::input() {
    Employee::input();

    cout << "Enter working days: ";
    cin >> workingDays;

    cout << "Enter allowance per day: ";
    cin >> allowancePerDay;
    cin.ignore();
}

void OfficeEmployee::display() const {
    Employee::display();
    cout << left
         << setw(15) << workingDays
         << setw(18) << fixed << setprecision(0) << allowancePerDay
         << setw(15) << fixed << setprecision(0) << calculateSalary()
         << setw(12) << getType()
         << endl;
}
