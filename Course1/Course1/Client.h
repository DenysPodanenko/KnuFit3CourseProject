#include<string>
#include<fstream>
#include<regex>
#include<algorithm>
#include "SitesDB.h"

using namespace std;

#pragma once
class Client
{
public:
	Client();
	~Client();

	void parseHistory(const string& path, SitesDB& db);
	int getE_commerceSites();
	int getBlogsAndPersonalSites();
	int getEntertainmentSites();
	int getEducationSites();
	int getOnlineCommunitySites();
	string getHistoryName();
private:
	string getSiteName(const string& site);

	string historyName;
	int e_commerceSites;
	int blogsAndPersonalSites;
	int entertainmentSites;
	int educationSites;
	int onlineCommunitySites;
};

