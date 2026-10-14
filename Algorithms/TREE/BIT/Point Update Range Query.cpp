
//Point update and Range query

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

const int MAX = 100005;
int BIT[MAX];

void update(int N,int index,int val)
{

	while(index<=N)
	{
		BIT[index] += val;
		index += (index&-index);
	}	

}

int query(int N,int index)
{
	
	int ans=0;
	while(index>0)
	{
		ans += BIT[index];
		index -= (index&-index);
	}

	return ans;

}

int main()
{

	int Q,N;
	int a,b,val,type;

	cin>>N>>Q;
	while(Q--)
	{
		cin>>type;
		switch(type)
		{
			case 0 : 	cin>>a>>val;
					update(N,a,val);
					break;
			case 1 : 	cin>>a>>b;
					cout<<query(N,b)-query(N,a-1)<<"\n";
					break;
		}
	}

	return 0;

}




















