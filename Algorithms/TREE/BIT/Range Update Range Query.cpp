
//Range Update and Range Query

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

const int MAX = 100005;
int BIT1[MAX],BIT2[MAX];
int N;

//In this case , we need 2 BIT 
//We find sum(1..p) by subtracting some value X from p*sum(p..p)
//If we update value v in [a..b] and 
//If p<a ,then X = 0
//If p>=a and p<=b , then X = v*(x-(a-1)) 
//If p>b , then X = -v*b+v*(a-1)

void update(int BIT[],int index,int val)
{

	while(index<=N)
	{

		BIT[index] += val;
		index += (index&-index);

	}

}

int query(int BIT[],int index)
{

	int ans=0;

	while(index>0)
	{

		ans += BIT[index];
		index -= (index&-index);

	}

	return ans;

}

int query(int index)
{

	return index*query(BIT1,index)-query(BIT2,index);

}

int main()
{

	int Q;
	int a,b,val,type;

	cin>>N>>Q;

	while(Q--)
	{

		cin>>type;

		switch(type)
		{

			case 0 : 	cin>>a>>b>>val;
					update(BIT1,a,val);
					update(BIT1,b+1,-val);
					update(BIT2,a,val*(a-1));
					update(BIT2,b+1,-val*b);
					break;

			case 1 : 	cin>>a>>b;
					cout<<query(b)-query(a-1)<<"\n";
					break;

		}

		//for(int i=1;i<=N;i++) cout<<BIT1[i]<<" ";
		//cout<<endl;
		//for(int i=1;i<=N;i++) cout<<BIT2[i]<<" ";
		//cout<<endl;

	}

	return 0;

}



























