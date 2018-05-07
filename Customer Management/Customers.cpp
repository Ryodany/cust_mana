#include "Customers.h"

bool Customers::addCustomer(const shared_ptr<Customer> &customer)
{
	bool ret = m_customers.insert(pair<unsigned long, shared_ptr<Customer>>(customer->getId(), customer)).second;
	if (ret)
		m_lastId++;
	return ret;
}

bool Customers::removeCustomer(unsigned long id)
{
	return m_customers.erase(id) > 0;
}

shared_ptr<Customer> Customers::getCustomerById(unsigned long id) const
{
	return m_customers.find(id)->second;
}

map<unsigned long, shared_ptr<Customer>> Customers::getCustomers() const
{
	return m_customers;
}

vector<Customer> Customers::returnCustomers() const
{
	vector<Customer> customers;
	for (auto &a = m_customers.begin(); a != m_customers.end(); a++)
		customers.push_back(*a->second);
	return customers;
}

vector<Customer> Customers::returnCustomers(string name) const
{
	vector<Customer> ret;
	for (auto &a = m_customers.begin(); a != m_customers.end(); a++)
	{
		if (a->second->getName() == name || a->second->getSurName() == name)
			ret.insert(ret.end(), *a->second);
	}
	return ret;
}

vector<unsigned long> Customers::returnIds() const
{
	vector<unsigned long> ids;
	// lambda for_each to push_back the ID of every customer
	for_each(m_customers.begin(), m_customers.end(), [&ids](const auto &it) { ids.push_back(it.first); });
	return ids;
}

unsigned long Customers::getLastId() const
{
	return m_lastId;
}

size_t Customers::getSize() const
{
	return m_customers.size();
}

map<unsigned long, shared_ptr<Customer>>::const_iterator Customers::begin()
{
	return m_customers.begin();
}

map<unsigned long, shared_ptr<Customer>>::const_iterator Customers::end()
{
	return m_customers.end();
}

bool operator<<(Customers &customers, const shared_ptr<Customer> &customer)
{
	return customers.addCustomer(customer);
}

bool operator>>(Customers &customers, unsigned long id)
{
	return customers.removeCustomer(id);
}
