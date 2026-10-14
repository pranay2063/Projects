
// 26 January 2016
// Depth First Search

#include<cmath>
#include<stack>
#include<vector>
#include<cstdio>
#include<climits>
#include<iostream>

using namespace std;
const int MAX = 100001;
void dfs(vector<int> adj[],int visited[],int parent[],int start)
{

	// non-recursive version
	stack<int> a;
	a.push(start);
	parent[start] = -1; // arbitrary value
	visited[start] = 1;

	while(!a.empty())
	{
		int u = a.top();
		cout<<u<<" ";
		a.pop();
		for(int i=0;i!=adj[u].size();i++)
		{
			int v = adj[u][i];
			if(!visited[v])	
			{
				visited[v] = 1;
				a.push(v);
				parent[v] = u;
			}
		}
	}

}

void dfs2(vector<int> adj[],int visited[],int parent[],int u)
{

	// recursive version
	cout<<u<<" ";
	visited[u] = 1;
	for(int i=0;i!=adj[u].size();i++)
	{
		int v = adj[u][i];
		if(!visited[v])
		{
			parent[v] = u;
			dfs2(adj,visited,parent,v);
		}
	}

}

int main()
{

	int n,m,a,b,i;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);  // Graph is assumed to be undirected
	}

	int visited[MAX] = {0};
	int parent[n+1];
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			parent[i] = -1;
			dfs(adj,visited,parent,i);
		}
	} 

	return 0;

}
























