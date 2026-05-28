#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "Employee.h"
#include "OfficeEmployee.h"
#include "ProductionEmployee.h"
#include <vector>
#include <memory>

class EmployeeManager {
private:
    vector<shared_ptr<Employee>> employees;

    int findIndexById(const string& id) const;
    vector<string> split(const string& line, char delimiter) const;

public:
    void addEmployee();
    void showAllEmployees() const;
    void searchById() const;
    void searchByName() const;
    void updateEmployee();
    void deleteEmployee();
    void sortBySalary();
    void sortByName();
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
