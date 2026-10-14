
// Union-find algorithm to analyse connected components in an undirected graph
// It is also used to detect cycle (self loop also) in an undirected graph

#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

const int MAX = 100001;

// p store the parent of the nodes
// rank[i] stores the height of the subtree of which i is the root
int p[MAX] = {0},rank[MAX] = {0};

int FIND_SET(int x)
{

	// function to return root of the connected component (subset) containing x
	// path compression is to flatten graph by connecting a node directly to its root
	if(x != p[x]) p[x] = FIND_SET(p[x]);
	return p[x];

}

bool MERGE_SET(int x, int y)
{

	// union by rank
	// add an edge between x and y
	// merge subsets containing x and y

	int rootx = FIND_SET(x);
	int rooty = FIND_SET(y);

	// if x and y belong to the same subset
	// connecting x and y leads to cycle in the graph
	if(rootx == rooty) return true;

	if(rank[rootx] > rank[rooty]) p[rooty] = rootx;
	else p[rootx] = rooty;

	// rank will increase only if subsets have same rank (or height)
	if(rank[rootx] == rank[rooty]) rank[rooty] += 1;

	return false; // cycle was not found and x & y were connected

}

int main(int argc, char const *argv[])
{
	int a,b,n,m;
	scanf("%d%d", &n, &m); // n is the number of nodes and m is the number of edges

	// Initially, all the nodes are parent of themselves and their rank is 0
	// After path compression, p[i] stores the root of the subset to which i belongs
	for(int i = 1; i <= n; ++i)
		p[i] = i, rank[i] = 0;

	bool ans = false;

	for(int i = 0; i < m; ++i)
	{

		scanf("%d%d", &a, &b);
		if(MERGE_SET(a,b))
			ans = true;
        /*
        for(int j =1; j <= n; j++)
            cout<<p[j]<<" ";
        cout<<endl;
        for(int j =1; j <= n; ++j)
            cout<<rank[j]<<" ";
        cout<<endl;
        */
	}

	if(ans) printf("cycle detected\n");

	return 0;
}
