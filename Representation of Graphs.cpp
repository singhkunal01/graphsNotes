/* ========================= GRAPH REPRESENTATION FUNCTIONS ============================*/
#include <bits/stdc++.h>
using namespace std;

//1.To Make the Adjacency Matrix.
vector<vector<int>> InputAdjacencyMatrix (int vert, int edges) {
	vector<vector<int>> adj(vert + 1, vector<int> (vert + 1, 0));
	for (int i = 0; i < edges; i++) {//it will iterate over number of edges
		int v1, v2;
		cin >> v1 >> v2;
		//for undirected graphs we have to take the input in two ways because inward and outward paths are same.
		adj[v1][v2] = 1;
		adj[v2][v1] = 1;//for directed graphs remove this line because it is not mendatory that edge between both the nodes in inward and outward both.
	}
	return adj;
}


//2.To Make the Adjacency List.
void InputAdjacencyList(int vert, int edges, vector<int> adj[]) {
	for (int i = 0; i < edges; i++) {//it will iterate over number of edges
		int v1, v2;
		cin >> v1 >> v2;
		//for undirected graphs we have to take the input in two ways because inward and outward paths are same.
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);//for directed graphs remove this line because it is not mendatory that edge between both the nodes in inward and outward both.
	}
}


//3.To Print the Adjacency List.
void printAdjList(vector<int> adj[], int vert) {
	for (int i = 0; i <= vert; i++) {
		cout << "[ (" << i << ") -> ";
		for (auto & v : adj[i])
			cout << v << ",";
		cout <<	 " ]" << endl;
	}
	cout << endl;
}


//4.ToMake the Adjacency List for directed graphs
void InputDirectedAdjacencyList(int &vert, int &edges, vector<int> adj[]) {
	for (int i = 0; i < edges; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);//for directed graphs we only need to make inward directed or outward directed edges
	}
}



//5.To take weighted graphs as input
void InputWeightedDirectedAdjacencyList(int &vert, int &edges, vector<pair<int, int>> adj[]) {
	for (int i = 0; i < edges; i++) {
		int v1, v2, weight;
		cin >> v1 >> v2 >> weight;
		adj[v1].push_back({v2, weight});
	}
}


//6.To Print the Adjacency List for weighted graphs
void printWeightedAdjList(vector<pair<int, int>> adj[], int vert) {
	for (int i = 0; i < vert; i++) {
		cerr << "[ (" << i << ") -> ";
		for (auto & v : adj[i])
			cerr << "{ " << v.first << "," << v.second << " }, ";
		cerr << " ]" << endl;
	}
	cerr << endl;
}



/*//How does it look like when your print your Adjacency List.
For the Graphs :
1 --------------   2                        Result Will Be :
| \                  \                      [ (0) ->  ]
|     \                 \                   [ (1) -> 2, 3, 5, ]
|          \              4                 [ (2) -> 1, 4, 3, ]
|              \        /                   [ (3) -> 2, 1, 4, 5, ]
|                 \   /                     [ (4) -> 2, 3, ]
5 --------------    3                       [ (5) -> 1, 3, ]
*/

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01