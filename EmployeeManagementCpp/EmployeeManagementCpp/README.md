# Employee Management System - C++

Ứng dụng quản lý dữ liệu nhân viên bằng **C++ hướng đối tượng**, phù hợp để đưa vào GitHub và CV cho vị trí Fresher/Intern IT.

## Mục tiêu project

Project mô phỏng hệ thống quản lý nhân viên trong công ty với các chức năng cơ bản:

- Thêm nhân viên
- Hiển thị danh sách nhân viên
- Tìm kiếm nhân viên theo mã hoặc tên
- Cập nhật thông tin nhân viên
- Xóa nhân viên
- Sắp xếp nhân viên theo lương hoặc tên
- Tính lương theo từng loại nhân viên
- Lưu dữ liệu ra file CSV
- Đọc dữ liệu từ file CSV

## Kiến thức áp dụng

- Lập trình hướng đối tượng OOP
- Class và Object
- Kế thừa
- Đa hình
- Hàm ảo
- Vector
- Xử lý chuỗi
- Tìm kiếm
- Sắp xếp
- Xử lý file
- Menu console

## Mô hình kế thừa

```text
Employee
├── OfficeEmployee
└── ProductionEmployee
```

## Loại nhân viên

### 1. Nhân viên văn phòng

Lương được tính theo công thức:

```text
salary = baseSalary + workingDays * allowancePerDay
```

### 2. Nhân viên sản xuất

Lương được tính theo công thức:

```text
salary = baseSalary + productQuantity * productPrice
```

## Cấu trúc thư mục

```text
EmployeeManagementCpp/
├── src/
│   ├── Employee.h
│   ├── Employee.cpp
│   ├── OfficeEmployee.h
│   ├── OfficeEmployee.cpp
│   ├── ProductionEmployee.h
│   ├── ProductionEmployee.cpp
│   ├── EmployeeManager.h
│   ├── EmployeeManager.cpp
│   └── main.cpp
├── data/
│   └── employees.csv
├── .gitignore
└── README.md
```

## Cách biên dịch và chạy

### Trên Windows dùng g++

```bash
g++ src/*.cpp -o employee_manager
employee_manager
```

### Trên Linux/macOS

```bash
g++ src/*.cpp -o employee_manager
./employee_manager
```

## Demo chức năng

```text
========== EMPLOYEE MANAGEMENT SYSTEM ==========
1. Add employee
2. Show all employees
3. Search employee by ID
4. Search employee by name
5. Update employee
6. Delete employee
7. Sort by salary
8. Sort by name
9. Save to file
10. Load from file
0. Exit
```

## Định hướng phát triển thêm

- Thêm đăng nhập Admin
- Xuất báo cáo lương
- Lọc nhân viên theo phòng ban
- Kết nối database MySQL
- Xây dựng giao diện bằng Qt hoặc web
