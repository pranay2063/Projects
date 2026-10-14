
// Breadth First Search

#include<queue>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

const int MAX = 100001;
std::vector<int> adj[MAX];

void BFS(int start, int visited[])
{

	queue<int> Q;
	Q.push(start);
	visited[start] = 1;

	while(!Q.empty())
	{
		int u = Q.front();
		printf("%d ", u);
		for(int i = 0; i != adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if(!visited[v])
			{
				visited[v] = 1;
				Q.push(v);
			}
		}

		Q.pop(); 
	}

}

int main()
{

	int a,b,n,m,i;
	scanf("%d%d",&n,&m); // n is the number of vertices and m is the number of edges

	for(i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int visited[MAX] = {0};
	for(i = 1; i <= n; ++i)
		if(!visited[i])
			BFS(i,visited);

	return 0;

}








