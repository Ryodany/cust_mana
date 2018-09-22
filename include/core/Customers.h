#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <stdint.h>

#include "core_pragma_lib.h"
#include "Customer.h"

// Exported class
class CORE_API Customers
{
	class Impl;
	Impl *m_pImpl;
public:
	Customers();
	Customers(const Customers &other) = delete;
	~Customers();
	bool addCustomer(std::unique_ptr<Customer> &&customer);
	bool removeCustomer(unsigned long id);

	std::shared_ptr<Customer> &&getCustomerById(unsigned long id);
	std::map<unsigned long, std::shared_ptr<Customer> > getCustomers() const;
	std::vector<Customer> returnCustomers() const;
	std::vector<Customer> returnCustomers(std::string name) const;
	std::vector<unsigned long> returnIds() const;
	unsigned long getLastId() const;
	std::size_t getSize() const;

	std::map<unsigned long, std::shared_ptr<Customer> >::iterator begin();
	std::map<unsigned long, std::shared_ptr<Customer> >::iterator end();
	
	// adds Customer
	friend bool operator<<(Customers &customers, std::unique_ptr<Customer> &&customer)
	{
		return customers.addCustomer(std::move(customer)); // pass ownership
	}

	// removes Customer
	friend bool operator>>(Customers &customers, unsigned long id)
	{
		return customers.removeCustomer(id);
	}


};

// Pointer to implementation (for dll export of STL)
class Customers::Impl
{
public:
	typedef std::map<unsigned long, std::shared_ptr<Customer> > CustomersMap;

	CustomersMap m_customers;
	unsigned long m_lastId = 0; // should be gathered from a file
};