#include <iostream>
#include "employee.h"
namespace Records {
	Employee::Employee(const std::string& firstName,
		const std::string& lastName)
		:m_firstName{ firstName }, m_lastName{ lastName }
	{
	}
	void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}
	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}
	void Employee::hire()
	{
		m_hired = true;
	}
	void Employee::fire()
	{
		m_hired = false;
	}
	void Employee::display() const
	{
		std::cout << "Name: " << getFirstName() << " " << getLastName() << std::endl;
		std::cout << "Employment: " << (isHired() ? "Current Employee" : "Former Employee") << std::endl;
		std::cout << "ID: " << getEmployeeNumber() << std::endl;
		std::cout << "Remuneration: " << getSalary() << std::endl;
	}
	void Employee::setFirstName(const std::string& firstName)
	{
		m_firstName = firstName;
	}
	const std::string& Employee::getFirstName() const
	{
		return m_firstName;
	}
	void Employee::setLastName(const std::string& lastName)
	{
		m_lastName = lastName;
	}
	const std::string& Employee::getLastName() const
	{
		return m_lastName;
	}
	void Employee::setEmployeeNumber(int employeeNumber)
	{
		m_employeeNumber = employeeNumber;
	}
	int Employee::getEmployeeNumber() const
	{
		return m_employeeNumber;
	}
	void Employee::setSalary(int salary)
	{
		m_salary = salary;
	}
	int Employee::getSalary() const
	{
		return m_salary;
	}
	bool Employee::isHired() const
	{
		return m_hired;
	}
}