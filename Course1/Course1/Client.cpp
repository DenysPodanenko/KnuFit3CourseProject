#include "Client.h"



Client::Client():hist(""), e_commerceSites(0), blogsAndPersonalSites(0), entertainmentSites(0), educationSites(0), onlineCommunitySites(0)
{
}


Client::~Client()
{
}

int Client::getBlogsAndPersonalSites()
{
	return blogsAndPersonalSites;
}

int Client::getEducationSites()
{
	return educationSites;
}

int Client::getEntertainmentSites()
{
	return entertainmentSites;
}

int Client::getE_commerceSites()
{
	return e_commerceSites;
}

int Client::getOnlineCommunitySites()
{
	return onlineCommunitySites;
}

string Client::getHistoryName()
{
	return historyName;
}

string Client::getSiteName(const string& site)
{
	string siteName;
	cmatch result;
	regex regHttps("(https\:\/\/)"
		"([.]*[^\/]+)");

	regex regHttp("(http\:\/\/)"
		"([.]*[^\/]+)");
	if (regex_search(site.c_str(), result, regHttps))
	{
		siteName = result[2];
	}
	else if (regex_search(site.c_str(), result, regHttp))
	{
		siteName = result[2];
	}

	return siteName;
}

void Client::parseHistory(const string& path, SitesDB& db)
{
	ifstream input(path);
	string line;
	hist = path;
	if (input)
	{
		string site;
		size_t pos = 0;

		while (getline(input, line))
		{
			pos = line.find('|');
			site = getSiteName(line.substr(pos + 1, line.length()));

			if (site!= "")
			{
				vector<string> sites = db.getE_commerceSites();
				if (find(sites.begin(), sites.end(), site) != sites.end())
				{
					e_commerceSites += 1;
					continue;
				}

				sites = db.getBlogsAndPersonalSites();
				if (find(sites.begin(), sites.end(), site) != sites.end())
				{
					blogsAndPersonalSites += 1;
					continue;
				}

				sites = db.getEntertainmentSites();
				if (find(sites.begin(), sites.end(), site) != sites.end())
				{
					entertainmentSites += 1;
					continue;
				}

				sites = db.getEducationSites();
				if (find(sites.begin(), sites.end(), site) != sites.end())
				{
					educationSites += 1;
					continue;
				}

				sites = db.getOnlineCommunitySites();
				if (find(sites.begin(), sites.end(), site) != sites.end())
				{
					onlineCommunitySites += 1;
					continue;
				}
			}
		}
	}
}