
// If there is back edge in a directed graph, then cycle is present in it
// Above statement can be proved using parenthesis theorem and white path theorem for directed graphs
// White path theorem : v is a descendant of u if and only if at time d[u], there is a path u->v consisting of only white vertices(not u)
// Cycle detection algorithm for undirected graphs can not be applied to directed graphs
// Due to nature of cycles in directed graphs, it is practical to use DFS

#include<stack>
#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

#define WHITE 0   // undiscovered
#define GRAY 1    // discovered but not finished
#define BLACK 2   // finished

const int MAX = 100001;
std::vector<int> adj[MAX];

bool DFS(int u, int color[])
{

	color[u] = GRAY; // discovered

	for(int i = 0; i != adj[u].size(); ++i)
	{

		int v = adj[u][i];
		if(color[v] == WHITE)
		{

			if(DFS(v,color))
				return true;

		}
		else if(color[v] == GRAY)
             		// if there is an edge from u(current) to v(adjacent) where v is only discovered and not finished
             		// then it is a back edge (edge to its ancestor) 
			return true;

	}

	color[u] = BLACK; // finished

	return false;

}

int main(int argc, char const *argv[])
{

	int a,b,n,m,i;
	scanf("%d%d",&n,&m);

	for(i = 0; i < m; ++i)
	{

		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		// Input graph is directed

	}

	int color[MAX] = {WHITE};

	for(i = 1; i <= n; ++i)
		if(color[i] == WHITE)
			if(DFS(i, color))
				printf("cycle detected\n");

	return 0;

}





