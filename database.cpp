#include <stdexcept>
#include <iostream>
#include "database.h"

namespace Records {
	Employee& Database::addEmployee(const std::string& firstName,
		const std::string& lastName)
	{
		Employee emp { firstName, lastName };
		emp.setEmployeeNumber(m_nextEmployeeNumber++);
		emp.hire();
		m_employees.push_back(emp); //Store the employee into a vector
		return m_employees.back();
	}

	Employee& Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : m_employees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		throw std::logic_error { "No employees found" };
	}

	Employee& Database::getEmployee(const std :: string& firstName,
		const std::string& lastName)
	{
		for (auto& employee : m_employees) {
			if ((employee.getFirstName() == firstName) && (employee.getLastName() == lastName)) {
				return employee;
			}
		}
		throw std::logic_error{ "No employees found" };
	}

	void Database::displayall() const
	{
		std::cout << "All Employee Information" << std::endl;
		for (auto& employee : m_employees) {
			employee.display();
			std::cout << std::endl;
		}
	}

	void Database::displayCurrent() const
	{
		std::cout << "Current Employee Information" << std::endl;
		for (auto& employee : m_employees) {
			if (employee.isHired()) {
				employee.display();
				std::cout << std::endl;
			}
		}
	}

	void Database::displayFormer() const
	{
		std::cout << "Former Employee Information" << std::endl;
		for (auto& employee : m_employees) {
			if (employee.isHired() == false) {
				employee.display();
				std::cout << std::endl;
			}
		}
	}
}