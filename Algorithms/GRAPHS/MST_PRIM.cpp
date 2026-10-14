#include<bits/stdc++.h>

using namespace std;

#define pp pair<int,int> 

void Prim(vector<pp> adj[], int V){
	priority_queue<pp, vector<pp>, greater<pp> > pq; //MinHeap to pick smallest vertex everytime

	vector<int> key(V, INT_MAX);	//stores key or value corresponding to a vertex
	vector<int> parent(V, -1);  	//stores parent of all the vertices
	vector<bool> visited(V, false);	//tracks if a vertex/node has been visited or not

	//start with vertex 0 or node 0
	key[0] = 0;
	parent[0] = -1;
	pq.push(make_pair(key[0], 0));

	while(!pq.empty()){
		int u = pq.top().second; //pick smallest node in cut which is not visited yet
		pq.pop(); //remove it from PQ
		visited[u] = true; //Mark it as visited as we do not have to visit it again
		for(int i = 0; i < adj[u].size(); ++i){
			//goto all elements adjacent to node u and update its key/value
			int v = adj[u][i].first;
			int weight = adj[u][i].second;
			if(visited[v] == false && weight < key[v]){
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	for(int i = 1; i < V; ++i)
		cout<<parent[i]<<" "<<i<<endl; //print edges in MST 

}

int main(){

	int n, m; //n is the number of vertices and m is the number of edges
	cin>>n>>m;

	int a,b,w;
	vector<pp> adj[n];
	for(int i = 0; i < m; ++i){
		cin>>a>>b>>w;
		//scan edge and corresponding weight
		//make adjacency list by adding edge and weight
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a, w));
	}
	
	Prim(adj, n);

	return 0;
}
