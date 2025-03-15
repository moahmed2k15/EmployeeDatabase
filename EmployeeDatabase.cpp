// EmployeeDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <exception>
#include <format>
#include <string>
#include "employee.h"
#include "database.h"

using namespace std;
using namespace Records;

static int displayMenu();
static void doHire(Database& db);
static void doFire(Database& db);
static void doPromote(Database& db);
int main()
{

	Database employeeDB;
	bool done{ false };
	while (!done) {
		int selection = { displayMenu() };
		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayall();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			cerr << "Unknown Command." << endl;
			break;
		}
	}

}

static int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employees" << endl;
	cout << "5) List all current employees" << endl;
	cout << "6) List all former employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";
	cin >> selection;
	return selection;
}

static void doHire(Database& db)
{
	string firstName, lastName;
	cout << "First Name? ";
	cin >> firstName;
	cout << "Last Name? ";
	cin >> lastName;

	auto& employee{ db.addEmployee(firstName, lastName) };
	cout << "Hired Employee " << firstName << " " << lastName << " bearing employee id: " << employee.getEmployeeNumber() << endl;

}

static void doFire(Database& db)
{
	int id;
	cout << "Employee ID? ";
	cin >> id;
	try {
		auto& employee = db.getEmployee(id);
		employee.fire();
		cout << "Terminated Employee " << employee.getFirstName() << " " << employee.getLastName() << " bearing employee id: " << employee.getEmployeeNumber() << endl;

	}
	catch (const logic_error& exception) {
		cerr << "Unable to terminate employee: " << exception.what() << endl;
	}
}

static void doPromote(Database& db)
{
	int id, raiseAmount;
	cout << "Employee ID? ";
	cin >> id;
	cout << "How much raise? ";
	cin >> raiseAmount;
	try {
		auto& employee = db.getEmployee(id);
		employee.promote(raiseAmount);
		cout << "Promoted Employee " << employee.getFirstName() << " " << employee.getLastName() << ". New Salary: " << employee.getSalary() << endl;

	}
	catch (const logic_error& exception) {
		cerr << "Unable to promote employee: " << exception.what() << endl;
	}
}