#include "EmployeeManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

int EmployeeManager::findIndexById(const string& id) const {
    for (int i = 0; i < (int)employees.size(); i++) {
        if (employees[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}

vector<string> EmployeeManager::split(const string& line, char delimiter) const {
    vector<string> result;
    string item;
    stringstream ss(line);

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}

void EmployeeManager::addEmployee() {
    int choice;
    cout << "\nChoose employee type:\n";
    cout << "1. Office employee\n";
    cout << "2. Production employee\n";
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore();

    shared_ptr<Employee> employee;

    if (choice == 1) {
        employee = make_shared<OfficeEmployee>();
    } else if (choice == 2) {
        employee = make_shared<ProductionEmployee>();
    } else {
        cout << "Invalid employee type!\n";
        return;
    }

    employee->input();

    if (findIndexById(employee->getId()) != -1) {
        cout << "Employee ID already exists!\n";
        return;
    }

    employees.push_back(employee);
    cout << "Employee added successfully!\n";
}

void EmployeeManager::showAllEmployees() const {
    if (employees.empty()) {
        cout << "Employee list is empty!\n";
        return;
    }

    cout << "\n";
    cout << left
         << setw(12) << "ID"
         << setw(25) << "Name"
         << setw(18) << "Department"
         << setw(15) << "Base Salary"
         << setw(15) << "Days/Qty"
         << setw(18) << "Allowance/Price"
         << setw(15) << "Salary"
         << setw(12) << "Type"
         << endl;

    cout << string(130, '-') << endl;

    for (const auto& employee : employees) {
        employee->display();
    }
}

void EmployeeManager::searchById() const {
    string id;
    cout << "Enter employee ID to search: ";
    getline(cin, id);

    int index = findIndexById(id);

    if (index == -1) {
        cout << "Employee not found!\n";
    } else {
        cout << "Employee found:\n";
        employees[index]->display();
    }
}

void EmployeeManager::searchByName() const {
    string keyword;
    bool found = false;

    cout << "Enter name keyword: ";
    getline(cin, keyword);

    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    for (const auto& employee : employees) {
        string name = employee->getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        if (name.find(keyword) != string::npos) {
            employee->display();
            found = true;
        }
    }

    if (!found) {
        cout << "No employee found!\n";
    }
}

void EmployeeManager::updateEmployee() {
    string id;
    cout << "Enter employee ID to update: ";
    getline(cin, id);

    int index = findIndexById(id);

    if (index == -1) {
        cout << "Employee not found!\n";
        return;
    }

    string name, department;
    double baseSalary;

    cout << "Enter new name: ";
    getline(cin, name);

    cout << "Enter new department: ";
    getline(cin, department);

    cout << "Enter new base salary: ";
    cin >> baseSalary;
    cin.ignore();

    employees[index]->setName(name);
    employees[index]->setDepartment(department);
    employees[index]->setBaseSalary(baseSalary);

    cout << "Employee updated successfully!\n";
}

void EmployeeManager::deleteEmployee() {
    string id;
    cout << "Enter employee ID to delete: ";
    getline(cin, id);

    int index = findIndexById(id);

    if (index == -1) {
        cout << "Employee not found!\n";
        return;
    }

    employees.erase(employees.begin() + index);
    cout << "Employee deleted successfully!\n";
}

void EmployeeManager::sortBySalary() {
    sort(employees.begin(), employees.end(),
         [](const shared_ptr<Employee>& a, const shared_ptr<Employee>& b) {
             return a->calculateSalary() > b->calculateSalary();
         });

    cout << "Employees sorted by salary descending!\n";
}

void EmployeeManager::sortByName() {
    sort(employees.begin(), employees.end(),
         [](const shared_ptr<Employee>& a, const shared_ptr<Employee>& b) {
             return a->getName() < b->getName();
         });

    cout << "Employees sorted by name ascending!\n";
}

void EmployeeManager::saveToFile(const string& filename) const {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Cannot open file for writing!\n";
        return;
    }

    for (const auto& employee : employees) {
        file << employee->toFileString() << endl;
    }

    file.close();
    cout << "Data saved to file successfully!\n";
}

void EmployeeManager::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Cannot open file for reading!\n";
        return;
    }

    employees.clear();

    string line;
    while (getline(file, line)) {
        vector<string> parts = split(line, ',');

        if (parts.size() != 7) {
            continue;
        }

        string type = parts[0];
        string id = parts[1];
        string name = parts[2];
        string department = parts[3];
        double baseSalary = stod(parts[4]);
        int value1 = stoi(parts[5]);
        double value2 = stod(parts[6]);

        if (type == "OFFICE") {
            employees.push_back(make_shared<OfficeEmployee>(
                id, name, department, baseSalary, value1, value2
            ));
        } else if (type == "PRODUCTION") {
            employees.push_back(make_shared<ProductionEmployee>(
                id, name, department, baseSalary, value1, value2
            ));
        }
    }

    file.close();
    cout << "Data loaded from file successfully!\n";
}
