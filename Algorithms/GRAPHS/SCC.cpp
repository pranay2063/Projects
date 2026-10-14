
// SCC (Strongly Connected Components)
// A graph is said to be strongly connected if there exists a path between any pair of vertices
// A connected undirected graph is always strongly connected
// For directed graphs, there can be many SCCs in it
// A directed graph is strongly connected if it has 1 SCC in it

// A DFS based solution has been proposed by Kosaraju which does DFS 2 times
// Time complexity of the approach is O(V+E) asymptotically

#include<stack>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>


using namespace std;

stack<int> S;
const int MAX = 100001;
std::vector<int> adj[MAX];   // adjacency list of a graph
std::vector<int> adjR[MAX];  // adjacency list of the transpose of the graph

void DFS(int u, vector<int> temp[], int visited[], int flag)
{

	if(flag == 2) printf("%d ", u); // print elements during DFS
	visited[u] = 1;

	for(int i = 0; i != temp[u].size(); ++i)
	{
		int v = temp[u][i];
		if(!visited[v])
			DFS(v, temp, visited, flag);
	}

	if(flag == 1) S.push(u);        // push elements to stack after their finishing time

}

bool SCC_check(int n)
{

	// A function to check if a graph is strongly connected
	// BFS can also work here

	int visited[MAX] = {0};

	// start DFS from any vertex of the graph
	DFS(1, adj, visited, 0); // assuming vertices start from 1

	// if any of the vertices is not visited, then return false
	for(int i = 1; i <= n; ++i)
		if(!visited[i])
			return false;

	memset(visited, 0, sizeof(visited));

	// start DFS from any vertex of the transpose of graph
	DFS(1, adjR, visited, 0);

	// if any of the vertices is not visited, then return false
	for(int i = 1; i <= n; ++i)
		if(!visited[i])
			return false;

	return true;

}

void SCC_find(int n)
{

	// A function to print all SCCs
	// A graph and its transpose have same SCCs

	int flag = 1;
	int visited[MAX] = {0};

	for(int i = 1; i <= n; ++i)
		if(!visited[i])
			DFS(i, adj, visited, flag);

	// After DFS, consider the nodes in decreasing order of their finishing time
	// S stores the nodes in decreasing order of their finishing times, ie, topological order
	// Pop elements from S and perform DFS from them as starting vertices if not visited

	flag = 2;
	int cnt = 0;  // to store the number of SCCs
	memset(visited, 0, sizeof(visited));

	while(!S.empty())
	{
		if(!visited[S.top()])
		{
        		++cnt;
            		printf("SCC%d : ", cnt);
			DFS(S.top(), adjR, visited, flag);
			printf("\n");
		}
		S.pop();
	}

}

int main()
{

	int a,b,n,m,i;
	scanf("%d%d",&n,&m); // n is the number of vertices and m is the number of edges

	for(i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);   // directed graph
		adjR[b].push_back(a);  // transpose of directed graph
	}

	if(SCC_check(n)) printf("The graph is strongly connected.\n");
	SCC_find(n);

	return 0;

}











