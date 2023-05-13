#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Employee structure
struct Employee
{
    string name;
    int age;
    int id;
    string designation;
    int salary;
};

// Function to add an employee
void addEmployee(vector<Employee> &employees)
{
    Employee emp;
    cout << "Enter name: ";
    getline(cin, emp.name);
    cout << "Enter age: ";
    cin >> emp.age;
    cout << "Enter ID: ";
    cin >> emp.id;
    cin.ignore();
    cout << "Enter designation: ";
    getline(cin, emp.designation);
    cout << "Enter salary: ";
    cin >> emp.salary;
    employees.push_back(emp);
    cout << "Employee added successfully!" << endl;
}

// Function to display all employees
void displayEmployees(vector<Employee> &employees)
{
    cout << "Employee List:" << endl;
    for (int i = 0; i < employees.size(); i++)
    {
        cout << "Name: " << employees[i].name << endl;
        cout << "Age: " << employees[i].age << endl;
        cout << "ID: " << employees[i].id << endl;
        cout << "Designation: " << employees[i].designation << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << endl;
    }
}

// Function to search for an employee by ID
void searchEmployee(vector<Employee> &employees)
{
    int id;
    cout << "Enter employee ID to search: ";
    cin >> id;
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].id == id)
        {
            cout << "Employee Found!" << endl;
            cout << "Name: " << employees[i].name << endl;
            cout << "Age: " << employees[i].age << endl;
            cout << "ID: " << employees[i].id << endl;
            cout << "Designation: " << employees[i].designation << endl;
            cout << "Salary: " << employees[i].salary << endl;
            return;
        }
    }
    cout << "Employee not found!" << endl;
}

// Function to modify an employee record
void modifyEmployee(vector<Employee> &employees)
{
    int id;
    cout << "Enter employee ID to modify: ";
    cin >> id;
    cin.ignore(); // ignore the newline character left in the input buffer
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].id == id)
        {
            cout << "Enter new name: ";
            getline(cin, employees[i].name);
            cout << "Enter new age: ";
            cin >> employees[i].age;
            cin.ignore();
            cout << "Enter new designation: ";
            getline(cin, employees[i].designation);
            cout << "Enter new salary: ";
            cin >> employees[i].salary;
            cout << "Employee modified successfully!" << endl;
            return;
        }
    }
    cout << "Employee not found!" << endl;
}

// Function to delete an employee record
void deleteEmployee(vector<Employee> &employees)
{
    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].id == id)
        {
            employees.erase(employees.begin() + i);
            cout << "Employee deleted successfully!" << endl;
            return;
        }
    }
    cout << "Employee not found!" << endl;
}

int main()
{
    vector<Employee> employees;
    int choice;
    do
    {
        cout << "Employee Management System" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Modify Employee" << endl;
        cout << "5. Delete Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            addEmployee(employees);
            break;
        case 2:
            displayEmployees(employees);
            break;
        case 3:
            searchEmployee(employees);
            break;
        case 4:
            modifyEmployee(employees);
            break;
        case 5:
            deleteEmployee(employees);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    } while (choice != 6);

    return 0;
}
