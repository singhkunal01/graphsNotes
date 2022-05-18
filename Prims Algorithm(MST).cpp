/*

What is Minimum spanning Tree ?

Ans- A minimum spanning tree (MST) or minimum weight spanning tree
is a subset of the edges of a connected, edge-weighted undirected graph that
connects all the vertices together, without any cycles and with the minimum possible
total edge weight.

*/


#include<bits/stdc++.h>
using namespace std;

// 1. Prims Algorithm - Brute Force
// TC - O(N^2 + ~N)

vector<int> primsAlgorithm(int vert, vector<pair<int, int>> adj[]) {
	vector<int> key(vert, INT_MAX), mstSet(vert, 0), parent(vert, -1);
//default
	key[0] = 0;
//total number of edges in MST are vertices - 1 so ,
	for (int i = 0; i < vert - 1 ; i++) {
		int mini = INT_MAX, u;
		for (int v = 0; v < vert; v++) {
			if (mstSet[v] == false and key[v] < mini) {
				mini = key[v], u = v;
			}
		}
		//mark the node as visited or the part of mst
		mstSet[u] = 1;
		//check or all adjacents of that current node
		for (auto &it : adj[u]) {
			int weight = it.second, node = it.first;
			if (mstSet[node] == false and weight < key[node]) {
				parent[node] = u, key[node] = weight;
			}
		}
	}
	return key;
}


//2. Efficient Approach using Priority Queue
vector<int> primsAlgorithmEfficient(int vert, vector<pair<int, int>> adj[]) {
	vector<int> key(vert, INT_MAX), mstSet(vert, 0), parent(vert, -1);
//default
	key[0] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
//total number of edges in MST are vertices - 1 so ,
	for (int i = 0; i < vert - 1 ; i++) {
//instead of findint minimum among all keys we use priority_queues of min heap so that everytime we get the min key in (logn)
		int u = pq.top().second;
		pq.pop();
		//mark the node as visited or the part of mst
		mstSet[u] = 1;
		//check or all adjacents of that current node
		for (auto &it : adj[u]) {
			int weight = it.second, node = it.first;
			if (mstSet[node] == false and weight < key[node]) {
				parent[node] = u, key[node] = weight;
				pq.push({key[node], node});//here first key is the min weight so that we sort accordingly and second is the node number
			}
		}
	}
	return key;
}



//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01