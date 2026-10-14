
//pranay2063

//27 september 2015

//RMQ with range updates

//We will not update all the nodes in the interval
//Only the maximal possible nodes will be updated 
//and their children will be marked for updation

#include<cstdio>
#include<climits>
#include<iostream>

using namespace std;

const int MAX = 100005;
int segtree[MAX],lazy[MAX]={0};

int query(int left,int right,int ql,int qr,int index)
{

	if(left>qr || right<ql)
	return INT_MAX;
 
	if(lazy[index]!=0)
	{

		segtree[index]+=lazy[index];

		if(left!=right)
		{

			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];

		}

		lazy[index]=0;

	}

	if(left>=ql && right<=qr)
	return segtree[index];

	int mid=(left+right)/2;

	return min(query(left,mid,ql,qr,2*index+1),query(mid+1,right,ql,qr,2*index+2));

}

void update(int left,int right,int upl,int upr,int val,int index)
{

	if(lazy[index]!=0)
	{

		segtree[index]+=lazy[index];

		if(left!=right)
		{

			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];

		}

		lazy[index]=0;

	}

	if(left>upr || right<upl)
	return ;

	if(left>=upl && right<=upr)
	{

		segtree[index]+=val;

		if(left!=right)
		{

			lazy[2*index+1]+=val;
			lazy[2*index+2]+=val;

		}

		return ;

	}

	int mid=(left+right)/2;

	update(left,mid,upl,upr,val,2*index+1);
	update(mid+1,right,upl,upr,val,2*index+2);

	segtree[index]=min(segtree[2*index+1],segtree[2*index+2]);

}

void build(int a[],int left,int right,int index)
{

	if(left==right)
	{

		segtree[index]=a[left];
		return ;

	}

	int mid=(left+right)/2;

	build(a,left,mid,2*index+1);
	build(a,mid+1,right,2*index+2);

	segtree[index]=min(segtree[2*index+1],segtree[2*index+2]);

}

int main()
{

	int n,Q,type,l,r,x,i;

	scanf("%d%d",&n,&Q);

	int a[n];

	for(i=0;i<n;i++)
	scanf("%d",&a[i]);

	build(a,0,n-1,0);

	while(Q--)
	{

		scanf("%d",&type);

		switch(type)
		{

			case 1 :   scanf("%d%d%d",&l,&r,&x); //updation
			     	   update(0,n-1,l-1,r-1,x,0);
			      	   break; 
	
			case 2 :   scanf("%d%d",&l,&r);      //query
			           printf("%d\n",query(0,n-1,l-1,r-1,0));	
			           break;

		}

	}

	return 0;

}




















