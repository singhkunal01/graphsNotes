#include <bits/stdc++.h>
using namespace std;

/*Shortest Distance from the source to each node using BFS algorithm */
vector<int> shortestDistanceFromSourceUndirected(int vert, vector<int>adj[], int source) {
	vector<int> distance(vert, INT_MAX);
	queue<int> ds({source});//push the source initially in this queue from where you want to find the shortest distance
	distance[source] = 0;//since the distance from source to the source is always 0.
	while (!ds.empty()) {
		int node = ds.front(); ds.pop();
		int cost = distance[node];
		for (auto &all : adj[node]) {
//check whether the current weight of the node in distance array is greater
			if  (distance[all] > cost + 1) {
				distance[all] = min(distance[all], cost + 1);
				ds.push(all);//only if the value is greater then we will push otherwise not
			}
		}
	}
	return distance;
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01