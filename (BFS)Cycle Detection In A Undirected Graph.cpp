/* ========================= GRAPH REPRESENTATION FUNCTIONS ============================*/
#include <bits/stdc++.h>
using namespace std;

/*.........................CYCLE DETECTION BY  BFS*.........................*/
bool isCyclicBFS(int node , int vert, vector<int> adj[], vector<int> &vis) {
	queue<pair<int, int>> ds({{node, -1}});
	vis[node] = 1;
	while (!ds.empty()) {
		int currNode = ds.front().first;
		int parent = ds.front().second;
		ds.pop();
		for (auto & nodes : adj[currNode]) {
			if (!vis[nodes]) {
				vis[nodes] = 1;
				ds.push({nodes, currNode});
			}
			else if (nodes != parent) {
				return true;
			}
		}
	}
	return false;
}

bool checkForCycleInAGrapBFS(int vert, vector<int> adj[]) {
	vector<int> vis(vert + 1, 0);
	for (int node = 1; node <= vert; node++) {
		if (!vis[node])
			if (isCyclicBFS(node, vert, adj, vis))
				return true;
	}
	return false;
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01