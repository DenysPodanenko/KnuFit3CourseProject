#include<string>
#include<vector>

using namespace std;

#pragma once
class SitesDB
{
public:
	SitesDB();
	~SitesDB();

	void setE_commerceSites(const vector<string>& e_commerceSites);
	void setBlogsAndPersonalSites(const vector<string>& blogsAndPersonalSites);
	void setEntertainmentSites(const vector<string>& entertainmentSites);
	void setEducationSites(const vector<string>& educationSites);
	void setOnlineCommunitySites(const vector<string>& onlineCommunitySites);

	vector<string> getE_commerceSites();
	vector<string> getBlogsAndPersonalSites();
	vector<string> getEntertainmentSites();
	vector<string> getEducationSites();
	vector<string> getOnlineCommunitySites();

private:
	vector<string> e_commerceSites;
	vector<string> blogsAndPersonalSites;
	vector<string> entertainmentSites;
	vector<string> educationSites;
	vector<string> onlineCommunitySites;
};

