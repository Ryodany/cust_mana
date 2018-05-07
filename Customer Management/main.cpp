#include <iostream>
#include <algorithm>
#include <time.h>

#include "Customers.h"
using namespace std;

template<typename K, typename V>
void printMapValues(pair<K, V> mapPair)
{
	cout << *mapPair.second << endl;
}

void processInput(int input, Customers &customers)
{
	if (input == 1) // print
	{
		if (customers.getSize() > 0)
			for_each(customers.begin(), customers.end(), printMapValues<unsigned long, shared_ptr<Customer>>);
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
		Software datisa("Datisa32", mktime(&y2k17), 39);
		// adding the customer through the operator<< overload I previously implemented
		if (customers << make_shared<Customer>(Customer(customers.getLastId(), name, surname, phoneNumber, datisa, yearsWithUs)))
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
		vector<Customer> results = customers.returnCustomers(inputStr);
		if (results.size() > 0)
		{
			// get every ID from the results
			vector<unsigned long> ids;
			for (auto &a : results)
			{
				ids.push_back(a.getId());
				cout << a << endl;
			}
			bool valid = false;
			unsigned long id;
			cout << "Which one do you want to remove? Please choose an ID "; cin >> id;
			do
			{
				// lambda function to find any ID matching in the list
				if (find_if(ids.begin(), ids.end(), [id](const unsigned long &i) { return i == id; } ) != ids.end())
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

int main()
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
	return 0;
}