#include <bits/stdc++.h>
using namespace  std;

//to check the cycle in directed graphs using DFS
bool havingCycleInDirectedGraph(vector<int> adj[], int node, vector<int> &vis, vector<int> &dfsVis) {
	vis[node] = 1, dfsVis[node] = 1;
	for (auto all : adj[node]) {

		if (!vis[all]) {
			if (havingCycleInDirectedGraph(adj, all, vis, dfsVis)) return true;
		}
		else if (dfsVis[all]) return true;
	}
	dfsVis[node] = 0; //unmark as visited
	return false;
}

bool checkCycleDirected(vector<int> adj[], int vert) {
	vector<int> vis(vert, 0), dfsVis(vert, 0);
	for (int i = 0; i < vert; i++) {
		if (!vis[i]) {
			if (havingCycleInDirectedGraph(adj, i, vis, dfsVis)) return true;
		}
	}
	return false;

}

// TC: O(N+E)
// SC: O(N+E)+O(N)+O(N)

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01