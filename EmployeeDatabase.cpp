// EmployeeDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "employee.h"
#include "database.h"

int main()
{
	using namespace Records;
	using namespace std;
	Database my_db;
	Employee& emp1 = my_db.addEmployee("Monem", "Ahmed");
	emp1.fire();

	Employee& emp2 = my_db.addEmployee("Muhib", "Ahmed");
	emp2.setSalary(100'000);

	Employee& emp3 = my_db.addEmployee("Ismat", "Meem");
	emp3.setSalary(120'000);
	emp3.promote(5'000);

	my_db.displayCurrent();
	my_db.displayFormer();
	my_db.displayall();


}