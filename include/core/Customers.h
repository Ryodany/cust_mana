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
	Impl *m_pImpl; // cannot use smart pointer because they are STL as well
public:
	typedef std::map<unsigned long, std::shared_ptr<Customer> > CustomersMap;

	Customers();
	// non-copyable, non-movable. Implemented the rule-of-five
	Customers(const Customers &other) = delete;
	Customers(Customers &&other) = delete;
	Customer &operator=(const Customers &other) = delete;
	Customer &operator=(Customers &&other) = delete;
	~Customers();

	bool addCustomer(std::unique_ptr<Customer> &&customer);
	bool removeCustomer(unsigned long id);

	std::shared_ptr<Customer> getCustomerById(unsigned long id);
	CustomersMap getCustomers() const;
	std::vector<std::shared_ptr<Customer> > returnCustomers() const;
	std::vector<std::shared_ptr<Customer> > returnCustomers(const std::string &name) const;
	std::vector<unsigned long> returnIds() const;
	unsigned long getLastId() const;
	std::size_t getSize() const;

	CustomersMap::iterator begin();
	CustomersMap::iterator end();
	
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