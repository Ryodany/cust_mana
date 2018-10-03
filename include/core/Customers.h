#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <stdint.h>

#include "core_pragma_lib.h"
#include "Customer.h"

// Exported class

/*
			------------------ IMPORTANTE NOTE ------------------
	If I didn't export the whole class and rather just export the public methods,
	I could have a smart pointer to Impl (i.e. std::unique_ptr<Impl> m_pImpl;)
*/
class CORE_API Customers
{
	class Impl;
	Impl *m_pImpl; // cannot use smart pointer because they are STL as well
public:
	using CustomersMap = std::map<unsigned long, std::shared_ptr<Customer> >;

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
	std::vector<std::reference_wrapper<Customer> > returnCustomers() const; // reference to Customer, instead of std::shared_ptr<Customer>
	std::vector<std::reference_wrapper<Customer> > returnCustomers(const std::string &name) const; // reference to Customer, instead of std::shared_ptr<Customer>
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