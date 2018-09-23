#include "Customer.h"

// Pointer to implementation (for dll export of STL) (also improves compile times and breaks dependencies with header file)
class Customer::Impl
{
public:
	Impl() : m_id(0), m_name(""), m_surname(""), m_phoneNumber(""), m_software("", 0, 0), m_yearsWithUs(0) { };
	Impl(unsigned long id, const std::string &name, const std::string &surname, const std::string &phoneNumber, const Software &software, size_t yearsWithUs = 0)
		: m_id(id), m_name(name), m_surname(surname), m_phoneNumber(phoneNumber), m_software(software), m_yearsWithUs(yearsWithUs) { };
	Impl(const Impl &other) : m_id(other.m_id), m_name(other.m_name), m_surname(other.m_surname), m_phoneNumber(other.m_phoneNumber), m_software(other.m_software), 
		m_yearsWithUs(other.m_yearsWithUs) { };
	Impl(Impl &&other) : m_id(std::move(other.m_id)), m_name(std::move(other.m_name)), m_surname(std::move(other.m_surname)), m_phoneNumber(std::move(other.m_phoneNumber)),
		m_software(std::move(other.m_software)), m_yearsWithUs(std::move(other.m_yearsWithUs)) 
	{
		// resetting primitive datatypes (std::move doesn't)
		other.m_id = 0;
		other.m_yearsWithUs = 0;
	};
	~Impl() { };

	Impl &operator=(const Impl &other)
	{
		if (&other != this)
		{
			m_id = other.m_id;
			m_name = other.m_name;
			m_surname = other.m_surname;
			m_phoneNumber = other.m_phoneNumber;
			m_yearsWithUs = other.m_yearsWithUs;
			m_software = other.m_software;
		}

		return *this;
	};

	Impl &operator=(Impl &&other)
	{
		if (&other != this)
		{
			m_id = std::move(other.m_id);
			m_name = std::move(other.m_name);
			m_surname = std::move(other.m_surname);
			m_phoneNumber = std::move(other.m_phoneNumber);
			m_yearsWithUs = std::move(other.m_yearsWithUs);
			m_software = std::move(other.m_software);

			// resetting primitive datatypes (std::move doesn't)
			other.m_id = 0;
			other.m_yearsWithUs = 0;
		}

		return *this;
	};

	unsigned long m_id;
	std::string m_name;
	std::string m_surname;
	std::string m_phoneNumber;
	size_t m_yearsWithUs;
	Software m_software;
};

Customer::Customer(unsigned long id, const std::string &name, const std::string &surname, const std::string &phoneNumber, 
	const Software &software, size_t yearsWithUs)
{
	m_pImpl = new Impl(id, name, surname, phoneNumber, std::move(software), yearsWithUs);
}

Customer::Customer(const Customer &other)
{
	if (&other != this)
	{
		if (m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}
		m_pImpl = new Impl();
		*m_pImpl = *other.m_pImpl;
	}
}

Customer::Customer(Customer &&other)
{
	if (&other != this)
	{
		if (m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}
		m_pImpl = new Impl();
		*m_pImpl = std::move(*other.m_pImpl);
	}
}

Customer &Customer::operator=(const Customer &other)
{
	if (&other != this)
	{
		if (m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}
		m_pImpl = new Impl();
		*m_pImpl = *other.m_pImpl;
	}

	return *this;
}

Customer &Customer::operator=(Customer &&other)
{
	if (&other != this)
	{
		if (m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}
		m_pImpl = new Impl();
		*m_pImpl = std::move(*other.m_pImpl);
	}

	return *this;
}

Customer::~Customer()
{
	delete m_pImpl;
}

unsigned long Customer::getId() const
{
	return m_pImpl->m_id;
}

std::string &Customer::getName()
{
	return m_pImpl->m_name;
}

std::string &Customer::getSurName()
{
	return m_pImpl->m_surname;
}

std::string Customer::getFullName() const
{
	return m_pImpl->m_name + " " + m_pImpl->m_surname;
}

std::string &Customer::getPhoneNumber()
{
	return m_pImpl->m_phoneNumber;
}

size_t Customer::getYearsWithUs() const
{
	return m_pImpl->m_yearsWithUs;
}

Software &Customer::getSoftware()
{
	return m_pImpl->m_software;
}
