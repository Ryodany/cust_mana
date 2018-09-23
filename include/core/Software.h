#pragma once
#include <string>
#include <time.h>
#include <memory>

#include "core_pragma_lib.h"

// Exported class
class CORE_API Software
{
	class Impl;
	Impl *m_pImpl; // cannot use smart pointer because they are STL as well
public:
	Software(const std::string &codename, time_t releaseDate, int licenseCost);
	// Implemented the rule-of-five
	Software(const Software &other);
	Software(Software &&other);
	Software &operator=(const Software &other);
	Software &operator=(Software &&other);
	~Software();

	std::string &getCodeName();
	time_t getReleaseDate() const;
	int getLicenseCost() const;

	void setCodeName(const std::string &codename);
	void setReleaseDate(time_t releaseDate);
	void setLicenseCost(int licenseCost);

};
