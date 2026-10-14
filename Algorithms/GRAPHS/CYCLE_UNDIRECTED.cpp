
// Both BFS or DFS can be used to detect cycle in an undirected graph
// Here, it is assumed that given graph is not multi-graph
// ie, there are no parallel edges between any 2 vertices

#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

const int MAX = 100001;
vector<int> adj[MAX];

bool DFS(int u, int visited[], int parent)
{

    	// In DFS, parent is recursively passed as parameter
	visited[u] = 1;

	for(int i = 0; i != adj[u].size(); ++i)
	{

		int v = adj[u][i];
		if(!visited[v])
		{

            		// In case of if1-if2-else, else is reached when if1 is true and if2 is false
            		if(DFS(v, visited, u))
				// if true, then only return in the middle of loop
				return true;

		}
		else if(v != parent)
			 // v is an adjacent node of u which is already visited and v is not parent of u
			 return true;

	}

	return false;

}

bool BFS(int start, int visited[], int n)
{

	// In case of BFS, extra memory is required to store parent of the nodes
	// Extra space : O(n)
	// In DFS, no such space is required as parent is passed as parameter in recursion

	queue<int> Q;
	Q.push(start);

	int parent[n+1];
	parent[start] = -1;
	visited[start] = 1;

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
				parent[v] = u;

			}
			else if(v != parent[u])
				 // v is an adjacent node of u which is already visited and v is not parent of u
				 return true;

		}

		Q.pop();

	}

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
		adj[b].push_back(a);
		// Input graph is undirected

	}

	int visited[MAX] = {0};

	for(i = 1; i <= n; ++i)
		if(!visited[i])
			if(DFS(i, visited, -1))
				printf("cycle detected DFS\n");

	memset(visited, 0, sizeof(visited));

	for(i = 1; i <= n; ++i)
		if(!visited[i])
			if(BFS(i, visited, n))
				printf("cycle detected BFS\n");

	return 0;

}




