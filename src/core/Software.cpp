#include "Software.h"

Software::Software(const std::string &codename, time_t releaseDate, int licenseCost)
{
	m_pImpl = new Impl(codename, releaseDate, licenseCost);
}

Software::Software(const Software &other)
{
	m_pImpl = new Impl(other.getCodeName(), other.getReleaseDate(), other.getLicenseCost());
}

Software::~Software()
{
	delete m_pImpl;
}

std::string Software::getCodeName() const
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
