#include "Cluster.h"



Cluster::Cluster()
{
}


Cluster::~Cluster()
{
}

bool Cluster::findClientInCluster(const vector<vector<Client>>& clusters, const Client& client)
{
	for (vector<Client> cluster : clusters)
	{
		if ((find(cluster.begin(), cluster.end(), client)) != cluster.end())
		{
			return true;
		}
	}

	return false;
}

double Cluster::getDistance(Client& c1, Client& c2)
{
	return sqrt(
		pow((c2.getBlogsAndPersonalSites() - c1.getBlogsAndPersonalSites()), 2) +
		pow((c2.getEducationSites() - c1.getEducationSites()), 2) +
		pow((c2.getEntertainmentSites() - c1.getEntertainmentSites()), 2) +
		pow((c2.getE_commerceSites() - c1.getE_commerceSites()), 2) +
		pow((c2.getOnlineCommunitySites() - c1.getOnlineCommunitySites()), 2)
	);
}

vector<Client> Cluster::getClientNeighbour(const vector<Client>& clients,Client& rootClient, const int& distance)
{
	vector<Client> neighbours;
	for (Client client : clients)
	{
		if (rootClient.getHistoryName() == client.getHistoryName())
		{
			continue;
		}

		if (getDistance(rootClient, client) <= distance)
		{
			neighbours.push_back(client);
		}
	}
}

vector<vector<Client>> Cluster::createClusters(vector<Client> clients, const int& distance, const int& minClientCluster)
{
	vector<vector<Client>> clusters;

	for (Client rootClient : clients)
	{
		if (!findClientInCluster(clusters, rootClient))
		{
			if (getClientNeighbour(clients, rootClient, distance).size() < minClientCluster)
			{
				continue;
			}
			else
			{
				vector<Client> cluster;
				cluster.push_back(rootClient);
				vector<Client> neighbours = getClientNeighbour(clients, rootClient, distance);

				for (Client neighbour : neighbours)
				{
					if (!findClientInCluster(clusters, neighbour))
					{
						cluster.push_back(neighbour);
					}
				}

				for (Client client : cluster)
				{
					vector<Client> neighbours = getClientNeighbour(clients, client, distance);
					if (neighbours.size() >= minClientCluster)
					{
						for (Client neighbour : neighbours)
						{
							if ((!findClientInCluster(clusters, neighbour)) &&
								(find(cluster.begin(), cluster.end(), neighbour) != cluster.end()))
							{
								cluster.push_back(neighbour);
							}
						}
					}
				}

				clusters.push_back(cluster);
			}
		}
	}

	return clusters;
}