#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <stdint.h>

#include "Customer.h"
using namespace std;

class Customers
{
public:
	Customers() { };
	~Customers() { };
	bool addCustomer(const shared_ptr<Customer> &customer);
	bool removeCustomer(unsigned long id);

	shared_ptr<Customer> getCustomerById(unsigned long id) const;
	map<unsigned long, shared_ptr<Customer>> getCustomers() const;
	vector<Customer> returnCustomers() const;
	vector<Customer> returnCustomers(string name) const;
	vector<unsigned long> returnIds() const;
	unsigned long getLastId() const;
	std::size_t getSize() const;

	map<unsigned long, shared_ptr<Customer>>::const_iterator begin();
	map<unsigned long, shared_ptr<Customer>>::const_iterator end();

	// adds Customer
	friend bool operator<<(Customers &customers, const shared_ptr<Customer> &customer);
	// removes Customer
	friend bool operator>>(Customers &customers, unsigned long id);

private:
	map<unsigned long, shared_ptr<Customer>> m_customers;
	unsigned long m_lastId = 0; // should be gathered from a file

};

