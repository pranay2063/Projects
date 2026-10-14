// Topological Sort
// Topological Sort can be implemented using DFS (both recursive and non-recursive)
// it is difficult to implement is using BFS
// Time complexity of the approach is O(V+E) 
// V is number of vertices and E is number of edges

#include<stack>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

const int MAX = 100001;
vector<int> adj[MAX];

// DFS - recursive and non-recursive
// BFS - non-recursive
// Topological Sort - DFS (recursive and non-recursive)

void TopologicalSort(int u, int visited[], stack<int> &S)
{

	// this is non-recursive version of Topological Sort
	// this approach is similar to DFS (Depth First Search)
	// concept of Topological Sort is that a node is not pushed to stack until all its adjacent nodes are pushed to it

	visited[u] = 1;
	stack<int> a;
	stack<int> temp;
	temp.push(u);

	while(!temp.empty())
	{

		int x = temp.top();
		a.push(x);
		temp.pop();

		for(int i=0; i != adj[x].size(); i++)
		{

			int v = adj[u][i];
			if(!visited[v])
			{

				visited[v] = 1;
				temp.push(v);

			}

		}

	}

	while(!a.empty())
	{

		S.push(a.top());
		a.pop();

	}

}

void TopologicalSortRecursive(int u, int visited[], stack<int> &S)
{

	// Topological Sort is valid only for DAG (Directed Acyclic Graphs)
	// this approach is similar to DFS (Depth First Search) with some modifications
	// Here all the nodes are called until leaf nodes are reached
	// Now, nodes are pushed during backtracking
	// Topological Sort : "A node is not pushed to stack until all its adjacent nodes are pushed to it"

	visited[u] = 1;

	for(int i=0; i != adj[u].size(); i++)
	{

		int v = adj[u][i];
		if(!visited[v])
		{

				visited[v] = 1;
				TopologicalSortRecursive(v, visited, S);

		}

	}

	S.push(u);

}

int main()
{

	int a,b,n,m,i;

	scanf("%d%d",&n,&m); // n is number of nodes(vertices) and m is the number of edges

	for(i=1; i<=m; i++)
	{
		// construction of adjacency list for the input graph
		scanf("%d%d",&a,&b); // a->b is a directed edge
		adj[a].push_back(b);

	}

	stack<int> S;
	int visited[MAX] = {0};

	for(i=1; i<=n; i++)
	{
        // function call can be started from any vertex of the graph
        // result will vary but it will be topological sort
		if(!visited[i])
			TopologicalSortRecursive(i, visited, S);

	}

	printf("Topological Sort of the Graph : \n");

	while(!S.empty())
	{

		printf("%d ", S.top());
		S.pop();

	}

}








