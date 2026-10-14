// Lowest Common Ancestor(LCA)

/* 

   Summary of the task :
  
   The lowest common ancestor (LCA) is a concept in graph theory and computer science. Let T be a rooted tree with N nodes.
   The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants
   (where we allow a node to be a descendant of itself). - Wikipedia

   The task in this problem is to find the LCA of any two given nodes v and w in a given tree T.
  
*/  

#include<bits/stdc++.h>
using namespace std;

vector<int> node[1001]; // array of vectors

int main()
{

    int t,i,m,n,num,cases;
    scanf("%d",&t);
    
    cases=t;
    while(t--)
    {

        scanf("%d",&n);
        vector<int> node[n+1];
        vector<int> parent(n+1,0);

        for(i=1;i<=n;i++)
        {
             scanf("%d",&m);
             // m is the number of children of i
             while(m--)
             {
                 scanf("%d",&num);
                 node[i].push_back(num);
                 // i is the parent of all the nodes being scanned
                 parent[num]=i;
             }
             // Here tree is being maintained as array of vectors with ith row containing children of i
        }

        int root;
        //find root
        //Root is the node which does not have any parent

        for(i=1;i<=n;i++)
        {
            if(parent[i]==0)
            {
                root=i;
                break;
            }
        }

        //printf("%d\n",root);
        
        //BFS
        int u,v;
        vector<bool> visited(n+1,false);
        vector<int> depth(n+1,0);
       
        //BFS traversal assigns depth of nodes according to height with root at highest depth and nodes at
        //same level at same depth

        queue<int> BFS;
        BFS.push(root);
        visited[root]=true;

        while(!BFS.empty())
        {
            u=BFS.front();
            for(i=0;i!=node[u].size();i++)
            {
                v=node[u][i];
                if(visited[v]==false)
                {
                    visited[v]=true;
                    depth[v]=depth[parent[v]]+1;
                    BFS.push(v);
                }
            }
            BFS.pop();
        }

        //Queries
        int Queries;
        scanf("%d",&Queries);
        printf("Case %d:\n",cases-t);

        while(Queries--)
        {
            scanf("%d%d",&u,&v);
            //Lowest Common Ancestor(LCA)
            if(depth[u]>depth[v])
               while(depth[u]>depth[v]) u=parent[u];
            else if(depth[u]<depth[v])
                 while(depth[u]<depth[v]) v=parent[v];

            while(u!=v)
            u=parent[u],v=parent[v];
            printf("%d\n",u);
        }

    }

    return 0;

}







