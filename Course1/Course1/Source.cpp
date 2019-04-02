#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>

#include "SitesDB.h"
#include "Client.h"
#include "Cluster.h"

using namespace std;
namespace fs = std::filesystem;

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

int main()
{
	SitesDB db;
	db.setE_commerceSites(readTXT("E-commerce.txt"));
	db.setBlogsAndPersonalSites(readTXT("BlogsSites.txt"));
	db.setEntertainmentSites(readTXT("Entertainment.txt"));
	db.setEducationSites(readTXT("Education.txt"));
	db.setOnlineCommunitySites(readTXT("OnlineCommunity.txt"));

	vector<Client> clients;

	string path = "clientHistorys";
	for (const auto& entry : fs::directory_iterator(path))
	{
		Client client;
		client.parseHistory(entry.path().string(), db);
		clients.push_back(client);
	}

	const int distance = 100;
	const int minClientCluster = 3;

	Cluster::createClusters(clients, distance, minClientCluster);

	return 0;
}