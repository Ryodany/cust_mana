#include "Customers.h"

// Pointer to implementation (for dll export of STL) (also improves compile times and breaks dependencies with header file)
class Customers::Impl
{
public:
	Impl() { };
	Impl(const Impl &other) : m_customers(other.m_customers) { };
	Impl(Impl &&other) : m_customers(std::move(other.m_customers)) { };
	~Impl() { };

	Impl &operator=(const Impl &other)
	{
		if (&other != this)
			m_customers = other.m_customers;

		return *this;
	};

	Impl &operator=(Impl &&other)
	{
		if (&other != this)
			m_customers = std::move(other.m_customers);

		return *this;
	};

	CustomersMap m_customers;
	unsigned long m_lastId = 0; // should be gathered from a file
};

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
	bool ret = m_pImpl->m_customers.insert(std::make_pair(customer->getId(), std::move(customer))).second; // passing ownership from the caller
	if (ret)
		m_pImpl->m_lastId++;
	return ret;
}

bool Customers::removeCustomer(unsigned long id)
{
	return m_pImpl->m_customers.erase(id) > 0;
}

std::shared_ptr<Customer> Customers::getCustomerById(unsigned long id)
{
	return m_pImpl->m_customers.find(id)->second;
}

std::map<unsigned long, std::shared_ptr<Customer> > Customers::getCustomers() const
{
	return m_pImpl->m_customers;
}

std::vector<std::reference_wrapper<Customer> > Customers::returnCustomers() const
{
	std::vector<std::reference_wrapper<Customer> > customers;
	for (Customers::CustomersMap::iterator itCustomer = m_pImpl->m_customers.begin(); itCustomer != m_pImpl->m_customers.end(); itCustomer++)
		customers.push_back(*itCustomer->second);
	return customers;
}

std::vector<std::reference_wrapper<Customer> > Customers::returnCustomers(const std::string &name) const
{
	std::vector<std::reference_wrapper<Customer> > ret;
	for (Customers::CustomersMap::iterator itCustomer = m_pImpl->m_customers.begin(); itCustomer != m_pImpl->m_customers.end(); itCustomer++)
	{
		if (itCustomer->second->getName() == name || itCustomer->second->getSurName() == name)
			ret.push_back(*itCustomer->second);
	}
	return ret;
}

std::vector<unsigned long> Customers::returnIds() const
{
	std::vector<unsigned long> ids;
	// lambda for_each to push_back the ID of every customer
	for_each(m_pImpl->m_customers.begin(), m_pImpl->m_customers.end(), [&ids](auto itCustomer) { ids.push_back(itCustomer.first); });
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

Customers::CustomersMap::iterator Customers::begin()
{
	return m_pImpl->m_customers.begin();
}

Customers::CustomersMap::iterator Customers::end()
{
	return m_pImpl->m_customers.end();
}