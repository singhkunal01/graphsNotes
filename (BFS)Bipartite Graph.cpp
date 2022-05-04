#include <bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int node, vector<int> adj[], vector<int> &color) {
	queue<int> ds({node});
	color[node] = 1;
	while (!ds.empty()) {
		int currNode = ds.front(); ds.pop();
		for (auto &all : adj[currNode]) {
			if (color[all] == -1) {
				color[all] = 1 - color[currNode];
				ds.push(all);
			}
			//else if check whether the adjacents of current node having same color or not if not then return false'
			else if (color[all] == color[currNode])
				return false;
		}
	}

	return true;
}

//main check function which return final answer
bool isBipartite(vector<int> adj[], int n) {
	vector<int> color(n, -1);
//for multiple components
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
//check for the bipartite
			if (!bipartiteBFS(i, adj, color)) return false;
		}
	}
	return true;

}

//and to check in the form of 2-D matrix instead of adjacency list check the main question on leetcode

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01