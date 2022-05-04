#include <bits/stdc++.h>
using namespace std;

/*Shortest Distance from the source to each node in a Weighted DAG*/
void dfsToposortWeightedDAG(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st) {
	vis[node] = 1;
	for (auto &it : adj[node]) {
		auto currNode = it.first;
		if (!vis[currNode]) {
			dfsToposortWeightedDAG(currNode, vis, adj, st);
		}
	}
	st.push(node);
}

vector<int> shortestDistanceInWeightedDAG(int vert, vector<pair<int, int>> adj[], int source) {
	vector<int> vis(vert, 0);
	stack<int> st;
	for (int i = 0; i < vert; i++) {
		if (!vis[i]) {
			dfsToposortWeightedDAG(i, vis, adj, st);
		}
	}
	vector<int> distance(vert, INT_MAX);
	distance[source] = 0;
	while (!st.empty()) {
		int node = st.top(); st.pop();
		if (distance[node] != INT_MAX) {
			for (auto &it : adj[node]) {
				auto currNode = it.first, currWeight = it.second;
				if (distance[currNode] > currWeight + distance[node]) {
					distance[currNode] = currWeight + distance[node];
				}
			}
		}
	}

	return distance;
}
