//================== RECURSIVE(DFS) TRAVERSAL OF A GRAPH ==================
void dfs(int node, vector<bool> &vis, vector<int> adj[], vector<int> &res) {
	res.push_back(node);//first insert the node in the resultant vector
	vis[node] = true;//and mark that node as a visited node
	for (auto eachNode : adj[node]) {
		if (!vis[eachNode]) {
			dfs(eachNode, vis, adj, res);
		}
	}
}
vector<int> dfsOfAGraph(int vert, vector<int> adj[]) {
	vector<int> resultDFS;//to store the result of dfs
	vector<bool> vis(vert + 1, false); //visited array
//check for every node in every component
	for (int node = 1; node <= vert; node++) {
//first check whether the node is visited or not
		if (!vis[node]) dfs(node, vis, adj, resultDFS);
	}
	return resultDFS;
}


// Note: To check the trial please check the BFS TRAVERSAL where i have given a solve() function use it to direct check 
// TC: O(N+E)
// SC: O(N+E)+O(N)+O(N)
