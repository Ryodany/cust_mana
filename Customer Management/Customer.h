#pragma once
#include <string>
#include <memory>

#include "Software.h"
using namespace std;

class Customer
{
public:
	Customer(unsigned long id, const string &name, const string &surname, const string &phoneNumber, const Software &software, size_t yearsWithUs = 0)
		: m_id(id), m_name(name), m_surname(surname), m_phoneNumber(phoneNumber), m_software(std::move(software)), m_yearsWithUs(yearsWithUs) { };
	Customer(const Customer &other) 
		: m_id(other.getId()), m_name(other.getName()), m_surname(other.getSurName()), m_phoneNumber(other.getPhoneNumber()), m_software(other.getSoftware()), 
		m_yearsWithUs(other.getYearsWithUs()) { };
	~Customer() { };
	unsigned long getId() const;
	string getName() const;
	string getSurName() const;
	string getFullName() const;
	string getPhoneNumber() const;
	size_t getYearsWithUs() const;
	Software getSoftware() const;

	friend ostream &operator<<(ostream &os, Customer &customer);

private:
	unsigned long m_id;
	string m_name;
	string m_surname;
	string m_phoneNumber;
	size_t m_yearsWithUs;
	Software m_software;
};

