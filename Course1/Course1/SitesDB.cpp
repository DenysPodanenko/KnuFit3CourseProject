#include "SitesDB.h"



SitesDB::SitesDB()
{
}


SitesDB::~SitesDB()
{
}

void SitesDB::setE_commerceSites(const vector<string>& e_commerceSites)
{
	this->e_commerceSites = e_commerceSites;
}
void SitesDB::setBlogsAndPersonalSites(const vector<string>& blogsAndPersonalSites)
{
	this->blogsAndPersonalSites = blogsAndPersonalSites;
}
void SitesDB::setEntertainmentSites(const vector<string>& entertainmentSites)
{
	this->entertainmentSites = entertainmentSites;
}
void SitesDB::setEducationSites(const vector<string>& educationSites)
{
	this->educationSites = educationSites;
}
void SitesDB::setOnlineCommunitySites(const vector<string>& onlineCommunitySites)
{
	this->onlineCommunitySites = onlineCommunitySites;
}

vector<string> SitesDB::getE_commerceSites()
{
	return e_commerceSites;
}
vector<string> SitesDB::getBlogsAndPersonalSites()
{
	return blogsAndPersonalSites;
}
vector<string> SitesDB::getEntertainmentSites()
{
	return entertainmentSites;
}
vector<string> SitesDB::getEducationSites()
{
	return educationSites;
}
vector<string> SitesDB::getOnlineCommunitySites()
{
	return onlineCommunitySites;
}