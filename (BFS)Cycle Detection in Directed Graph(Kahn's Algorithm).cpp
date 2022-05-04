#include <bits/stdc++.h>
using namespace std;

/*Check cycle in Directed graph using BFS algorithm similar to Kahn's algorithm*/
bool isCyclicDFSDirected(int vert, vector<int> adj[]) {
	vector<int> indegree(vert, 0);
	//first calculate the indegree for each node
	for (int i = 0; i < vert; i++) {
		for (auto &node : adj[i]) {
			indegree[node]++;
		}
	}
	queue<int> topo;
	for (int i = 0; i < vert; i++) {
		if (indegree[i] == 0) topo.push(i);
	}
	int count = 0;
	while (!topo.empty()) {
		int node = topo.front();
		topo.pop();
		count++;
		for (auto &it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) topo.push(it);
		}
	}
	return count == vert;
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01