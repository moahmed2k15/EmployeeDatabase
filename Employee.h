#pragma once
#include <string>
namespace Records {
	const int DefaultStartingSalary { 30'000 };
	const int DefaultRaiseAndDemeritAmount{ 1'000 };

	class Employee {
	public:
		Employee(const std::string& firstName,
				 const std::string& lastName);
		void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
		void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
		void hire();
		void fire();
		void display() const;
		
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int salary);
		int getSalary() const;

		bool isHired() const;

	private:
		std::string m_firstName, m_lastName;
		int m_employeeNumber { -1 };
		int m_salary { DefaultStartingSalary };
		bool m_hired{ false };



	};

}