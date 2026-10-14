
// Code to check if a graph is bipartite
// This code works only for those graphs which are strongly connected
// m-coloring problem can be used here, where m = 2

#include<queue>
#include<vector> 
#include<cstdio>
#include<iostream>

using namespace std;

const int MAX = 100001;
std::vector<int> adj[MAX];

bool bipartite_check(int start, int visited[])
{

	// BFS or DFS can be used to check if a graph is bipartite
	// But, the graph here must be strongly connected 
	// Here, 2-coloring problem can be implemented using BFS or DFS

	int color[MAX] = {0};

	queue<int> Q;
	Q.push(start);
	visited[start] = 1;
	color[start] = 0;

	while(!Q.empty())
	{

		int u = Q.front();
		for(int i = 0; i != adj[u].size(); ++i)
		{

			int v = adj[u][i];
			if(!visited[v])
			{

				visited[v] = 1;
				Q.push(v);
				color[v] = 1 - color[u];
				// v will be assigned color opposite to that of u

			}	
			else if(color[u]+color[v] != 1)
				 // if u and v have same color at any moment, then the graph is not bipartite
				 return false;

		}	

		Q.pop();

	}

	return true;

}

int main()
{

	int a,b,n,m,i,type;

	scanf("%d%d",&n,&m); // n is the number of vertices and m is the number of edges
	printf("directed graph(0) and undirected graph(1) : ");
	scanf("%d",&type);   // 0 for directed graph and 1 for undirected graph

	for(i = 0; i < m; ++i)
	{

		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		if(type) adj[b].push_back(a);

	}	

	int visited[MAX] = {0};
	if(bipartite_check(1,visited)) printf("Given graph is bipartite");
	else printf("Given graph is not bipartite");

	return 0;

}










