#include<iostream>
#include <ctime>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include<tuple>
#include<algorithm>

using namespace std;

string getSiteName(const string& site)
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

vector<string> readTXT(const string& path)
{
	vector<string> output;
	ifstream input(path);
	string line;
	if (input)
	{
		while (getline(input, line))
		{
			output.push_back(line);
		}
	}

	return output;
}

tuple<vector<string>, vector<string>> parseHistory(const string& path)
{
	vector<string> dates;
	vector<string> sites;

	ifstream input("history_export.txt");
	string line;

	if (input)
	{
		string date;
		string site;
		size_t pos = 0;

		while (getline(input, line))
		{
			pos = line.find('|');
			date = line.substr(0, pos);
			site = line.substr(pos + 1, line.length());

			if (getSiteName(site) != "")
			{
				dates.push_back(date);
				sites.push_back(getSiteName(site));
			}
		}
	}

	return { dates,sites };
}

void main()
{
	vector<string> dates, sites;
	tie(dates, sites) = parseHistory("history_expotr.txt");
	vector<string> e_commerceSites = readTXT("E-commerce.txt");
	vector<string> blogsAndPersonalSites = readTXT("BlogsSites.txt");
	vector<string> entertainmentSites = readTXT("Entertainment.txt");
	vector<string> educationSites = readTXT("Education.txt");
	vector<string> onlineCommunitySites = readTXT("OnlineCommunity.txt");

	vector<int> point = { 0,0,0,0,0 };
	for (string site : sites)
	{
		if (find(e_commerceSites.begin(), e_commerceSites.end(), site) != e_commerceSites.end())
		{
			point[0] += 1;
			continue;
		}
		else if (find(blogsAndPersonalSites.begin(), blogsAndPersonalSites.end(), site) != blogsAndPersonalSites.end())
		{
			point[1] += 1;
			continue;
		}
		else if (find(entertainmentSites.begin(), entertainmentSites.end(), site) != entertainmentSites.end())
		{
			point[2] += 1;
			continue;
		}
		else if (find(educationSites.begin(), educationSites.end(), site) != educationSites.end())
		{
			point[3] += 1;
			continue;
		}
		else if (find(onlineCommunitySites.begin(), onlineCommunitySites.end(), site) != onlineCommunitySites.end())
		{
			point[4] += 1;
		}
	}

}