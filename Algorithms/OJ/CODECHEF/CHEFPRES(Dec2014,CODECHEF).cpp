// Problem Link : http://www.codechef.com/problems/CHEFPRES/

/*

  Summary of the question :

   If city B is the capital of a kingdom and the king lives here. 
     
   Specifically, suppose Chef will be living in the city A. For each city i, let G(i) be the smallest distance between B
   and any city on the unique path connecting cities A and i. Chef wants to travel to the city C such that:
   1)  F(C)=P
   2)  There is no other city D having F(D)=P and G(D) > G(C).
   
   If there are several cities with this property, Chef will choose the one with the smallest number. It is possible that 
   C may equal A, in which case he does not have to travel at all.
   
   Chef has not yet decided which city to live in, nor which recipe to create. You are required to answer several queries
   for him - if he lives in city A, and requires product P, which city should he travel to in order to purchase it?

*/

#include<bits/stdc++.h>

using namespace std;

vector<int> product[10001]; // Array of vectors
vector<int> parent(10001),value(10001);

void solve(int chef,int p)
{

    if(product[p].empty())
    printf("-1\n");

    else {

          //find the longest common ancestor(LCA) of chef and each city having product p where root is the capital city

          int result=-1,i,j,k,max=INT_MIN,LCA;

          for(int i=0;i!=product[p].size();i++)
          {

              int city=product[p][i],start=chef;

              if(value[city]>value[start])
              while(value[city]>value[start])  city=parent[city];

              else if(value[start]>value[city])
                   while(value[start]>value[city]) start=parent[start];

              while(start!=city)
              {

                  start=parent[start];

                  city=parent[city];

              }

              LCA=start;

              /*

              vector<int> path1,path2;

              while(start!=-1)
              {

                 path1.push_back(start);
                 start=parent[start];

              }

              start=city;

              while(start!=-1)
              {

                 path2.push_back(start);
                 start=parent[start];

              }

              if(path1.empty())
              j=-1;

              else j=path1.size()-1;

              if(path2.empty())
              k=-1;

              else k=path2.size()-1;

              for(;j>=0 && k>=0;j--,k--)
              {

                  if(path1[j]!=path2[k])
                  break;

                  else LCA=path1[j];

              }

              */


              if(value[LCA]>max)
              {

                  result=product[p][i];
                  max=value[LCA];

              }
             else if(value[LCA]==max && product[p][i]<result)
                  {

                      result=product[p][i];

                  }

          }//end of i loop

          printf("%d\n",result);

    }//end of else

}

int main(int argc,char **argv)
{

    int n,k,b,i,city1,city2;

    //cin>>n>>k>>b;
    scanf("%d%d%d",&n,&k,&b);

    vector<int> graph[n+1];

    for(i=1;i<n;i++){


            //cin>>city1>>city2;
            scanf("%d%d",&city1,&city2);

            graph[city1].push_back(city2);
            graph[city2].push_back(city1);

    }

    //vector<int> parent(n+1),value(n+1);
    vector<bool> visited(n+1,false);

    queue<int> BFS;

    BFS.push(b);

    visited[b]=true;
    value[b]=0;

    while(!BFS.empty())
    {

        int u=BFS.front();

        for(i=0;i!=graph[u].size();i++)
        {

            int v=graph[u][i];

            if(visited[v]==false)
            {

                visited[v]=true;
                BFS.push(v);
                parent[v]=u;
                value[v]=value[parent[v]]+1;

            }

        }

        BFS.pop();

    }

    parent[b]=-1;

    int f;

    for(i=1;i<=n;i++)
    {

        //cin>>f;
        scanf("%d",&f);

        product[f].push_back(i);

        //cout<<visited[i]<<endl;

    }

    int Queries,a,p;

    //cin>>Queries;
    scanf("%d",&Queries);

    while(Queries--)
    {

        //cin>>a>>p;
        scanf("%d%d",&a,&p);

        //cout<<solve(a,p)<<endl;
        solve(a,p);

    }

    return 0;

}
















