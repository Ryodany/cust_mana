#include "Customer.h"

unsigned long Customer::getId() const
{
	return m_id;
}

string Customer::getName() const
{
	return m_name;
}

string Customer::getSurName() const
{
	return m_surname;
}

string Customer::getFullName() const
{
	return m_name + " " + m_surname;
}

string Customer::getPhoneNumber() const
{
	return m_phoneNumber;
}

size_t Customer::getYearsWithUs() const
{
	return m_yearsWithUs;
}

Software Customer::getSoftware() const
{
	return m_software;
}

ostream &operator<<(ostream &os, Customer &customer)
{
	os << "ID: " << customer.getId() << endl << "Full Name: " << customer.getFullName() << endl;
	os << "Phone Number: " << (customer.getPhoneNumber() != "" ? customer.getPhoneNumber() : "Undefined") << endl;
	os << "Purchased Software: " << (customer.getSoftware().getCodeName() != "" ? customer.getSoftware().getCodeName() : "Undefined") << endl;
	os << "Years with us: " << customer.getYearsWithUs() << endl;
	return os;
}
