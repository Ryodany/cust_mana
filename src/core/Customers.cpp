#include "Customers.h"

Customers::Customers()
{
	m_pImpl = new Impl();
}

Customers::~Customers()
{
	delete m_pImpl;
}

bool Customers::addCustomer(std::unique_ptr<Customer> &&customer)
{
	bool ret = m_pImpl->m_customers.insert(make_pair(customer->getId(), std::move(customer))).second; // passing ownership from the caller
	if (ret)
		m_pImpl->m_lastId++;
	return ret;
}

bool Customers::removeCustomer(unsigned long id)
{
	return m_pImpl->m_customers.erase(id) > 0;
}

std::shared_ptr<Customer> &&Customers::getCustomerById(unsigned long id)
{
	return std::move(m_pImpl->m_customers.find(id)->second); // pass ownership
}

std::map<unsigned long, std::shared_ptr<Customer> > Customers::getCustomers() const
{
	return m_pImpl->m_customers;
}

std::vector<Customer> Customers::returnCustomers() const
{
	std::vector<Customer> customers;
	for (auto a = m_pImpl->m_customers.begin(); a != m_pImpl->m_customers.end(); a++)
		customers.push_back(*a->second);
	return customers;
}

std::vector<Customer> Customers::returnCustomers(std::string name) const
{
	std::vector<Customer> ret;
	for (auto a = m_pImpl->m_customers.begin(); a != m_pImpl->m_customers.end(); a++)
	{
		if (a->second->getName() == name || a->second->getSurName() == name)
			ret.insert(ret.end(), *a->second);
	}
	return ret;
}

std::vector<unsigned long> Customers::returnIds() const
{
	std::vector<unsigned long> ids;
	// lambda for_each to push_back the ID of every customer
	for_each(m_pImpl->m_customers.begin(), m_pImpl->m_customers.end(), [&ids](auto it) { ids.push_back(it.first); });
	return ids;
}

unsigned long Customers::getLastId() const
{
	return m_pImpl->m_lastId;
}

size_t Customers::getSize() const
{
	return m_pImpl->m_customers.size();
}

std::map<unsigned long, std::shared_ptr<Customer> >::iterator Customers::begin()
{
	return m_pImpl->m_customers.begin();
}

std::map<unsigned long, std::shared_ptr<Customer> >::iterator Customers::end()
{
	return m_pImpl->m_customers.end();
}