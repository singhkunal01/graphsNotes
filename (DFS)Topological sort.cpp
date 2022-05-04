#include<bits/stdc++.h>
using namespace std;

void helpToposortDFS(int node, vector<int> adj[], vector<int>&vis, stack<int> &st) {
	vis[node] = 1; //mark the node as visited
//check the node is visited or not for all adjacents
	for (auto &all : adj[node]) {
		if (!vis[all]) {
			helpToposortDFS(all, adj, vis, st);
		}
	}
	//push the value in stack after the call is over
	st.push(node);
}

vector<int> topologicalSort(int vert, vector<int> adj[]) {
	vector<int> vis(vert, 0), res;
	stack<int> st;
	//for multiple components
	for (int i = 0; i < vert; i++) {
		if (!vis[i])
			helpToposortDFS(i, adj, vis, st);
	}
	//now as we pass the stack for the answer no we have to take out all of those values
	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}
	return res;

	//this is the final result
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01