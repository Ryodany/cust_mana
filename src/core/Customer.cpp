#include "Customer.h"

Customer::Customer(unsigned long id, const std::string &name, const std::string &surname, const std::string &phoneNumber, 
	const Software &software, size_t yearsWithUs)
{
	m_pImpl = new Impl(id, name, surname, phoneNumber, std::move(software), yearsWithUs);
}

Customer::Customer(const Customer &other)
{
	m_pImpl = new Impl(other.getId(), other.getName(), other.getSurName(), other.getPhoneNumber(), std::move(other.getSoftware()), other.getYearsWithUs());
}

Customer::~Customer()
{
	delete m_pImpl;
}

unsigned long Customer::getId() const
{
	return m_pImpl->m_id;
}

std::string Customer::getName() const
{
	return m_pImpl->m_name;
}

std::string Customer::getSurName() const
{
	return m_pImpl->m_surname;
}

std::string Customer::getFullName() const
{
	return m_pImpl->m_name + " " + m_pImpl->m_surname;
}

std::string Customer::getPhoneNumber() const
{
	return m_pImpl->m_phoneNumber;
}

size_t Customer::getYearsWithUs() const
{
	return m_pImpl->m_yearsWithUs;
}

Software Customer::getSoftware() const
{
	return m_pImpl->m_software;
}
