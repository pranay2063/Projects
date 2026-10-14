#include<bits/stdc++.h>

using namespace std;

#define pp pair<int,int> 

void Dijkstra(vector<pp> adj[], int V){
	//single source shortest path algorithm
	priority_queue<pp, vector<pp>, greater<pp> > pq; //MinHeap to pick smallest vertex everytime

	vector<int> dist(V, INT_MAX);	//stores distance corresponding to a vertex
	vector<bool> visited(V, false);	//tracks if a vertex/node has been visited or not

	//start with vertex 0 or node 0
	dist[0] = 0;
	pq.push(make_pair(dist[0], 0));

	while(!pq.empty()){
		int u = pq.top().second; //pick smallest node in heap which is not visited yet
		pq.pop(); //remove it from PQ
		visited[u] = true; //Mark it as visited as we do not have to visit it again
		for(int i = 0; i < adj[u].size(); ++i){
			//goto all elements adjacent to node u and update its distance if required
			int v = adj[u][i].first;
			int weight = adj[u][i].second;
			if(visited[v] == false && dist[u]+weight < dist[v]){
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	for(int i = 0; i < V; ++i)
		cout<<"0 -> "<<i<<" : "<<dist[i]<<endl; //print distance of vertices from starting vertex 0

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
	
	Dijkstra(adj, n);

	return 0;
}
