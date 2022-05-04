// ========================== DETECT THE CYCLE USING DFS APPROACH IN A UNDIRECTED GRAPH ====================
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(pair<int, int> &currPrev, vector<bool> &vis, vector<int> adj[]) {
	int node = currPrev.first;                      //this stores the current Node .
	int parent = currPrev.second;                   //this stores the parent of current Node .
	vis[node] = true;                               //first mark the current node as visited
	for (auto eachNode : adj[node]) {
		currPrev = {eachNode, node};
		if (!vis[eachNode]) {
			/* INTUTION: First check whether the node is visited or not ,if the node is not visited then call the same function and if the current node is visited then
			 go and check the parent that its parent is same as the current node or not if not then return true (means it has a cycle) */
			if (isCyclic(currPrev, vis, adj))
				return true;
		}
		else if (eachNode != parent)
			return true;
	}
	return false;
}


bool checkForCycleInAGraph(int vert, vector<int> adj[]) {
	vector<bool> vis(vert + 1, false);
	pair<int, int> currPrev; int parent = -1;           //initially mark the parent as -1 after than it will change
	for (int node = 1; node <= vert; node++) {
		currPrev = {node, parent};                       // it stores the current Node and the parent of that node so that we can check the cycle easil
		if (!vis[node])
			if (isCyclic(currPrev, vis, adj))
				return true;
	}
	return false;
}

// THIS IS JUST FOR  USE SO THAT YOU CAN EXECUTE IT DIRECTLY (Make sure that the InputAdjacencyList() function is not defined here so please for that refer GRAPH PRESENTATION code .

void solve() {
	int vert, edges;
	cin >> vert >> edges;
	vector<int> adjList[vert + 1];//adjacency list to represent the graph
	InputAdjacencyList(vert, edges, adjList);//taking graphs edges and vertices as a input
	if (checkForCycleInAGraph(vert, adjList)) cout << "Is Cyclic" << newl;
	else cout << "Is Not Cyclic" << newl;

}

// TC: O(N+E)
// SC: O(N+E)+O(N)+O(N)

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01