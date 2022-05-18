#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int ranks[100000];

//this is the default set inititally
void makeSet(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;//for every component initially the parent is he itself
		ranks[i] = 0;
	}
}

//function to find the parent of node
int findParent(int node) {
	//if the node is parent itself
	if (node == parent[node]) return node;
	//otherwise from starting to end it find its parent
	// return findParent(parent[node]); this is the simple step

	// but for the path compression we need to keep track of parents so that no need to traverse over other nodes
	return parent[node] = findParent(parent[node]);
}

//main union function
void unionFinder(int first, int second) {
	first = findParent(first);//find the ultimate parent of both nodes
	second = findParent(second);
	/*	three conditions if the rank of first is less than the rank of second ,
	if the rank of first is greater than the rank of second and if the ranks of boths are equal */
	if (ranks[first] < ranks[second]) {
		parent[first] = second;
	}
	else if (ranks[first] > ranks[second]) {
		parent[second] = first;
	}
	else {
		parent[second] = first;
		//increase the levels of ranks
		ranks[first]++;
	}
}

void disjointSet() {
	//full name of this algorithm is disjoint set algorithm
	int n;
	cin >> n;
	makeSet(n);
	int operations;
	cin >> operations;
	while (operations--) {
		int u, v;
		cin >> u >> v;
		unionFinder(u, v);
	}
//check whether the nodes we entered belongs to the same task or not
	/*if (findParent(node1) != findParent(node2)) cout << "Different Components";
	else cout << "Same Components";*/
}
