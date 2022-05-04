/*................................CYCLE DETECTION BY DFS................................*/
#include <bits/stdc++.h>
using namespace std;

bool bipartiteDFS(int node, vector<int> adj[], vector<int> &color) {
	if (color[node] == -1)	color[node] = 1;//if it is not colored then first color it
	for (auto &all : adj[node]) {
		if (color[all] == -1) {
			color[all] = 1 - color[node];//mark with opposite color
			if (!bipartiteDFS(all, adj, color)) return false;
		}
		//else if check whether the adjacents of current node having same color or not if not then return false'
		else if (color[all] == color[node])
			return false;
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
			if (!bipartiteDFS(i, adj, color)) return false;
		}
	}
	return true;

}


//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01