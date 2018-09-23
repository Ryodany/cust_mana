#include <iostream>
#include <algorithm>
#include <time.h>

#include "main_pragma_lib.h"
#include "core/Customers.h"

using namespace std;

template<typename K, typename V>
void printMapValues(pair<K, V> &mapPair)
{
	cout << *mapPair.second << endl;
}

// non-templated function for unique_ptr printing
void printCustomers(Customer &customer)
{
	cout << customer << endl;
}

void testSoftware(const Software &software)
{
	// testing copy and move constructors and operators
	Software softwareDummy{ software };
	Software softwareCopy = softwareDummy;
	Software softwareCopy2 = softwareDummy;
	Software softwareCopy3 = softwareCopy;
	Software softwareCopy4{ softwareDummy };
	Software softwareMove = std::move(softwareCopy);
}

void testCustomer(const Customer &customer)
{
	// testing copy and move constructors and operators
	Customer customerDummy{ customer };
	Customer customerCopy = customerDummy;
	Customer customerCopy2 = customerDummy;
	Customer customerCopy3 = customerCopy;
	Customer customerCopy4{ customerDummy };
	Customer customerMove = std::move(customerCopy);
}

void processInput(int input, Customers &customers)
{
	if (input == 1) // print
	{
		if (customers.getSize() > 0)
			for_each(customers.begin(), customers.end(), printMapValues<const unsigned long, shared_ptr<Customer> >);
		else
			cout << "No customers found" << endl << endl;
	}
	else if (input == 2) // add customer
	{
		string name, surname, phoneNumber; size_t yearsWithUs;
		cout << "Please enter the following data: " << endl;
		cout << "Name: "; cin >> name;
		cout << "Surname: "; cin >> surname;
		cout << "Phone number: "; cin >> phoneNumber;
		cout << "Years with us: "; cin >> yearsWithUs;
		/*
			it should ask for the name of the software (it may be good to add in the future the possibility to set multiple softwares
			for each customer, in case they want more than one) and look up	for the rest of the data regarding that software,
			but I will make a dummy one for now.
		*/
		struct tm y2k17 = { 0 };
		y2k17.tm_year = 117;
		Software datisa{ "Datisa32", mktime(&y2k17), 39 };
		//testSoftware(datisa);

		Customer customer{ customers.getLastId(), name, surname, phoneNumber, datisa, yearsWithUs };
		//testCustomer(customer);
		
		// adding the customer through the operator<< overload I previously implemented
		if (customers << make_unique<Customer>(customer))
			cout << "Customer added successfully" << endl << endl;
		else
			cout << "Unexpected error occurred when trying to add that customer" << endl << endl;
	}
	else if (input == 3) // remove customer
	{
		if (customers.getSize() == 0)
		{
			cout << "No customers found" << endl << endl;
			return;
		}

		string inputStr;
		cout << "What's the name or surname of the customer you want to remove from the database? "; cin >> inputStr;
		vector<std::shared_ptr<Customer> > results = customers.returnCustomers(inputStr);
		if (results.size() > 0)
		{
			// get every ID from the results
			vector<unsigned long> ids;
			for (std::shared_ptr<Customer> customer : results)
			{
				ids.push_back(customer->getId());
				cout << *customer << endl;
			}

			bool valid = false;
			unsigned long id;
			cout << "Which one do you want to remove? Please choose an ID "; cin >> id;
			do
			{
				// lambda function to find any ID matching in the list
				if (find_if(ids.begin(), ids.end(), [id](const unsigned long &i) { return i == id; }) != ids.end())
					valid = true;
				if (!valid)
				{
					cout << "That ID is not in the list in front of you. Try again: ";
					cin >> id;
				}
			} while (!valid);

			// removing the customer through the operator>> overload I previously implemented
			if (customers >> id)
				cout << "Customer " << id << " has been removed successfully" << endl << endl;
			else
				cout << "Customer " << id << " not found" << endl << endl;
		}
		else
			cout << "No matches for that name" << endl << endl;
	}
	else if (input == 0);
	else
		cout << "Invalid input" << endl << endl;
}

void asd()
{
	int input;
	Customers customers;
	do
	{
		cout << "1. List customers" << endl;
		cout << "2. Add customer" << endl;
		cout << "3. Remove customer" << endl;
		cout << "0. Exit" << endl;
		cin >> input;
		processInput(input, customers);
	} while (input != 0);
}

int main()
{
	asd();

	return 0;
}