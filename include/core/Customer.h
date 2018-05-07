#pragma once
#include <string>
#include <memory>

#include "core_pragma_lib.h"
#include "Software.h"

// Exported class
class CORE_API Customer
{
	class Impl;
	Impl *m_pImpl;
public:
	Customer(unsigned long id, const std::string &name, const std::string &surname, const std::string &phoneNumber, 
		const Software &software, size_t yearsWithUs = 0);
	Customer(const Customer &other);
	~Customer();

	unsigned long getId() const;
	std::string getName() const;
	std::string getSurName() const;
	std::string getFullName() const;
	std::string getPhoneNumber() const;
	size_t getYearsWithUs() const;
	Software getSoftware() const;


	friend std::ostream &operator<<(std::ostream &os, Customer &customer)
	{
		os << "ID: " << customer.getId() << std::endl << "Full Name: " << customer.getFullName() << std::endl;
		os << "Phone Number: " << (customer.getPhoneNumber() != "" ? customer.getPhoneNumber() : "Undefined") << std::endl;
		os << "Purchased Software: " << (customer.getSoftware().getCodeName() != "" ? customer.getSoftware().getCodeName() : "Undefined") << std::endl;
		os << "Years with us: " << customer.getYearsWithUs() << std::endl;
		return os;
	}
};

// Pointer to implementation (for dll export of STL)
class Customer::Impl
{
public:
	Impl(unsigned long id, const std::string &name, const std::string &surname, const std::string &phoneNumber, const Software &software, size_t yearsWithUs = 0)
		: m_id(id), m_name(name), m_surname(surname), m_phoneNumber(phoneNumber), m_software(std::move(software)), m_yearsWithUs(yearsWithUs) { };

	unsigned long m_id;
	std::string m_name;
	std::string m_surname;
	std::string m_phoneNumber;
	size_t m_yearsWithUs;
	Software m_software;
};