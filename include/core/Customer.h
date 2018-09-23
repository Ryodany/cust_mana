#pragma once
#include <iostream>
#include <string>
#include <memory>

#include "core_pragma_lib.h"
#include "Software.h"

// Exported class
class CORE_API Customer
{
	class Impl;
	Impl *m_pImpl; // cannot use smart pointer because they are STL as well
public:
	Customer(unsigned long id, const std::string &name, const std::string &surname, const std::string &phoneNumber, 
		const Software &software, size_t yearsWithUs = 0);
	// Implemented the rule-of-five
	Customer(const Customer &other);
	Customer(Customer &&other);
	Customer &operator=(const Customer &other);
	Customer &operator=(Customer &&other);
	~Customer();

	unsigned long getId() const;
	std::string &getName();
	std::string &getSurName();
	std::string &getPhoneNumber();
	size_t getYearsWithUs() const;
	Software &getSoftware();

	std::string getFullName() const;

	friend std::ostream &operator<<(std::ostream &os, Customer &customer)
	{
		os << "ID: " << customer.getId() << std::endl << "Full Name: " << customer.getFullName() << std::endl;
		os << "Phone Number: " << (customer.getPhoneNumber() != "" ? customer.getPhoneNumber() : "Undefined") << std::endl;
		os << "Purchased Software: " << (customer.getSoftware().getCodeName() != "" ? customer.getSoftware().getCodeName() : "Undefined") << std::endl;
		os << "Years with us: " << customer.getYearsWithUs() << std::endl;
		return os;
	}
};
