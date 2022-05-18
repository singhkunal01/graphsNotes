#include<bits/stdc++.h>
using namespace std;

/*SHORTEST PATH ALGORITHMS STARTED - DIJKSTRA'S ALGORITHM */
vector<int> dijkstraAlgorithm(int vert, vector<pair<int, int>> adj[], int source) {
	//make sure that you would take min heap type priority queue so that the node having minimum distance is always at top
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ds;
	ds.push({0, source});
	vector<int> distance(vert + 1, INT_MAX);
	//the distance of source from source is always 0 so,
	distance[source] = 0;
	while (!ds.empty()) {
		auto fullNode = ds.top();
		ds.pop();
		int weight = fullNode.first, node = fullNode.second;
		for (auto &it : adj[node]) {
			int newWeight = weight + it.second;
			if ( newWeight < distance[it.first]) {
				distance[it.first] = newWeight;
				ds.push({newWeight, it.first});
			}
		}
	}
	return distance;
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01