#include<vector>
#include<string>
#include"Client.h"
#include<algorithm>

#pragma once
class Cluster
{
public:
	Cluster();
	~Cluster();

	static bool findClientInCluster(const vector<vector<Client>>& clusters, const Client& client);
	static double getDistance(Client& c1, Client& c2);
	static vector<Client> getClientNeighbour(const vector<Client>& clients, Client& rootClient, const int& distance);
	static vector<vector<Client>> createClusters(vector<Client> clients, const int& distance, const int& minClientCluster);
};