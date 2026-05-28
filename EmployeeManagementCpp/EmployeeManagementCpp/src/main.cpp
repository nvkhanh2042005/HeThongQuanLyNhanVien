#include "EmployeeManager.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "\n========== EMPLOYEE MANAGEMENT SYSTEM ==========\n";
    cout << "1. Add employee\n";
    cout << "2. Show all employees\n";
    cout << "3. Search employee by ID\n";
    cout << "4. Search employee by name\n";
    cout << "5. Update employee\n";
    cout << "6. Delete employee\n";
    cout << "7. Sort by salary\n";
    cout << "8. Sort by name\n";
    cout << "9. Save to file\n";
    cout << "10. Load from file\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

int main() {
    EmployeeManager manager;
    int choice;
    const string filename = "data/employees.csv";

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                manager.addEmployee();
                break;
            case 2:
                manager.showAllEmployees();
                break;
            case 3:
                manager.searchById();
                break;
            case 4:
                manager.searchByName();
                break;
            case 5:
                manager.updateEmployee();
                break;
            case 6:
                manager.deleteEmployee();
                break;
            case 7:
                manager.sortBySalary();
                manager.showAllEmployees();
                break;
            case 8:
                manager.sortByName();
                manager.showAllEmployees();
                break;
            case 9:
                manager.saveToFile(filename);
                break;
            case 10:
                manager.loadFromFile(filename);
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
