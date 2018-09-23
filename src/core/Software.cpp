#include "Software.h"

// Pointer to implementation (for dll export of STL) (also improves compile times and breaks dependencies with header file)
class Software::Impl
{
public:
	Impl() : m_codename(""), m_releaseDate(0), m_licenseCost(0) { };
	Impl(const std::string &codename, time_t releaseDate, int licenseCost) : m_codename(codename),
		m_releaseDate(releaseDate), m_licenseCost(licenseCost) { };
	Impl(const Impl &other) : m_codename(other.m_codename), m_releaseDate(other.m_releaseDate), m_licenseCost(other.m_licenseCost) { };
	Impl(Impl &&other) : m_codename(std::move(other.m_codename)), m_releaseDate(std::move(other.m_releaseDate)), m_licenseCost(std::move(other.m_licenseCost)) 
	{
		// resetting primitive datatypes (std::move doesn't)
		other.m_releaseDate = 0;
		other.m_licenseCost = 0;
	};
	~Impl() { };

	Impl &operator=(const Impl &other)
	{
		if (&other != this)
		{
			m_codename = other.m_codename;
			m_releaseDate = other.m_releaseDate;
			m_licenseCost = other.m_licenseCost;
		}

		return *this;
	};

	Impl &operator=(Impl &&other)
	{
		if (&other != this)
		{
			m_codename = std::move(other.m_codename);
			m_releaseDate = std::move(other.m_releaseDate);
			m_licenseCost = std::move(other.m_licenseCost);
			// resetting primitive datatypes (std::move doesn't)
			other.m_releaseDate = 0;
			other.m_licenseCost = 0;
		}

		return *this;
	};

	std::string m_codename;
	time_t m_releaseDate;
	int m_licenseCost;
};

Software::Software(const std::string &codename, time_t releaseDate, int licenseCost)
{
	m_pImpl = new Impl(codename, releaseDate, licenseCost);
}

Software::Software(const Software &other)
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

Software::Software(Software &&other)
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

Software &Software::operator=(const Software &other)
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

Software &Software::operator=(Software &&other)
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

Software::~Software()
{
	delete m_pImpl;
}

std::string &Software::getCodeName()
{
	return m_pImpl->m_codename;
}

time_t Software::getReleaseDate() const
{
	return m_pImpl->m_releaseDate;
}

int Software::getLicenseCost() const
{
	return m_pImpl->m_licenseCost;
}

void Software::setCodeName(const std::string &codename)
{
	m_pImpl->m_codename = codename;
}

void Software::setReleaseDate(time_t releaseDate)
{
	m_pImpl->m_releaseDate = releaseDate;
}

void Software::setLicenseCost(int licenseCost)
{
	m_pImpl->m_licenseCost = licenseCost;
}
