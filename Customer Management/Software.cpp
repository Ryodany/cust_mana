#include "Software.h"

string Software::getCodeName()
{
	return m_codename;
}

time_t Software::getReleaseDate()
{
	return m_releaseDate;
}

int Software::getLicenseCost()
{
	return m_licenseCost;
}

void Software::setCodeName(const string &codename)
{
	m_codename = codename;
}

void Software::setReleaseDate(time_t releaseDate)
{
	m_releaseDate = releaseDate;
}

void Software::setLicenseCost(int licenseCost)
{
	m_licenseCost = licenseCost;
}
