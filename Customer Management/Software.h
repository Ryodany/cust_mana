#pragma once
#include <string>
#include <time.h>

using namespace std;
class Software
{
public:
	Software(const string &codename, time_t releaseDate, int licenseCost) :
		m_codename(codename),
		m_releaseDate(releaseDate),
		m_licenseCost(licenseCost) { };
	~Software() { };

	string getCodeName();
	time_t getReleaseDate();
	int getLicenseCost();

	void setCodeName(const string &codename);
	void setReleaseDate(time_t releaseDate);
	void setLicenseCost(int licenseCost);

private:
	string m_codename;
	time_t m_releaseDate;
	int m_licenseCost;
};

