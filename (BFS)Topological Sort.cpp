#include<bits/stdc++.h>
using namespace std;

// Note : This algorithm is Also known as KAHN's algorithm

/*.............Topological sort using BFS traversal Also called as Kahn's Algorithm.............*/

vector<int> topologicalSortBFS(int vert, vector<int> adj[]) {
	vector<int> indegre(vert, 0);
	//calculate the indegree of each node( number of incoming edges)
	for (int v = 0; v < vert; v++) {
		for (auto node : adj[v]) {
			indegre[node]++;
		}
	}
	//now push all the nodes having indegree equals 0 in queue
	queue<int> topo;
	for (int v = 0; v < vert; v++ ) {
		if (indegre[v] == 0) topo.push(v);
	}
	//now do this process until the queue doesn't becomes zero
	vector<int> resTopoSort;
	while (!topo.empty()) {
		int node = topo.front();
		topo.pop();
		resTopoSort.push_back(node);
		//now check for adjacents
		for (auto &all : adj[node]) {
//decrease the indegree of that node
			indegre[all]--;
			if (indegre[all] == 0) {
				topo.push(all);
			}
		}
	}
	return resTopoSort;
}



// TC: O(N+E)
// SC: O(N)+O(N)=O(2N)

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01