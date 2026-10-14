
#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>
#define ppp pair<int,pair<int,int> >

int find(int v, vector<int> &parent){
	if(parent[v] != v) parent[v] = find(parent[v], parent); //path compression
	return parent[v];
}

void merge(int x, int y, vector<int> &parent, vector<int> &size){
	int px = find(x,parent);
	int py = find(y,parent);

	if(px != py){
		//merge smaller subset into larger subset - compression by size
		if(size[px] > size[py]){
			parent[py] = px;
			size[px] += size[py];
		}
		else{
			parent[px] = py;
			size[py] += size[px];
		}
	
	}
}

int Kruskal(vector<ppp> edges, int V){
	
	vector<int> parent(V); //stores parent of all vertices (parent of subsets)
	vector<int> size(V, 1); //stores size of subtree of a subset
	
	for(int i = 0; i < V; ++i)
		parent[i] = i; //initially parent of all vertices is same vertices itself
	
	sort(edges.begin(), edges.end()); //sort all edges based on weight
	
	//pick edges one by one and add it to MST if it does not form cycle
	int MST_sum = 0;
	for(int i = 0; i < edges.size(); ++i){
		int x = edges[i].second.first;
		int y = edges[i].second.second;
		int px = find(x, parent);
		int py = find(y, parent);
		
		if(px != py){
			cout<<x<<" "<<y<<endl;
			MST_sum += edges[i].first;
			merge(px,py,parent,size);
		}

	}
	
	return MST_sum;
}

int main(){

	int n, m; //n is the number of vertices and m is the number of edges
	cin>>n>>m;

	int a,b,w;
	vector<ppp> edges;
	for(int i = 0; i < m; ++i){
		cin>>a>>b>>w;
		//scan edge and corresponding weight
		//make adjacency list by adding edge and weight
		edges.push_back(make_pair(w,make_pair(a,b)));
	}
	
	cout<<"Sum of edges in MST : "<<Kruskal(edges, n);

	return 0;
}
