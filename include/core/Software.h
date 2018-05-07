#pragma once
#include <string>
#include <time.h>
#include <memory>

#include "core_pragma_lib.h"

// Exported class
class CORE_API Software
{
	class Impl;
	Impl *m_pImpl;
public:
	Software(const std::string &codename, time_t releaseDate, int licenseCost);
	Software(const Software &other);
	~Software();

	std::string getCodeName() const;
	time_t getReleaseDate() const;
	int getLicenseCost() const;

	void setCodeName(const std::string &codename);
	void setReleaseDate(time_t releaseDate);
	void setLicenseCost(int licenseCost);

};

// Pointer to implementation (for dll export of STL)
class Software::Impl
{
public:
	Impl(const std::string &codename, time_t releaseDate, int licenseCost) : m_codename(codename),
		m_releaseDate(releaseDate), m_licenseCost(licenseCost) { };

	std::string m_codename;
	time_t m_releaseDate;
	int m_licenseCost;
};