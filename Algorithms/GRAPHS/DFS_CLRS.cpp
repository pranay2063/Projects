
// DFS (Depth First Search)

#include<stack>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

#define WHITE 0   // undiscovered
#define GRAY 1    // discovered but not finished
#define BLACK 2   // finished

const int MAX = 100001;

int time;
int d[MAX],f[MAX];           // d stores discovery time and f stores finishing time
std::vector<int> adj[MAX];   // adjacency list of a graph

void DFS(int u, int color[])
{

	cout<<u<<" ";
	color[u] = GRAY; // discovered
	time = time + 1;
	d[u] = time;

	for(int i = 0; i != adj[u].size(); ++i)
	{

		int v = adj[u][i];
		if(color[v] == WHITE)
			DFS(v, color);

	}

	color[u] = BLACK; // finished
	time = time + 1;
	f[u] = time;

}

int main()
{

	int a,b,n,m,i;

	scanf("%d%d",&n,&m); // n is the number of vertices and m is the number of edges

	for(i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);   // assuming graph to be undirected
		adj[b].push_back(a);
	}

	int color[MAX] = {WHITE};

	for(i = 1; i <= n; ++i)
		if(color[i] == WHITE)
			DFS(i, color);

    	//for(i=1;i<=n;i++)
        //cout<<i<<" "<<d[i]<<" "<<f[i]<<endl;

	return 0;

}








