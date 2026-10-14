
//pranay2063

//27 september 2015

//Range sum with interval update

//Consider the problem of printing range sum queries using segment tree
//Only change is that now we have range updates and not single update
//So , in this case , we will be lazy during updates
//This means we will not update all the nodes in the interval
//Only the maximal possible nodes will be updated 
//and their children will be marked for updation

#include<cstdio>
#include<iostream>

using namespace std;

#define ll long long

const int MAX = 100005; 
ll segtree[4*MAX],lazy[4*MAX]={0};

ll query(int left,int right,int ql,int qr,int index)
{

	if(left>qr || right<ql)
	return 0;

	if(lazy[index]!=0)
	{

		//past updation is to be done
	
		segtree[index]+=(ll)(right-left+1)*lazy[index];

		if(left!=right)
		{

			//this is not a leat node
			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];

		}

		lazy[index]=0;

	}	

	if(left>=ql && right<=qr)
	return segtree[index];

	int mid=(left+right)/2;

	return query(left,mid,ql,qr,2*index+1)+query(mid+1,right,ql,qr,2*index+2);

}

void update(int left,int right,int upl,int upr,int val,int index)
{

	if(lazy[index]!=0)
	{

		//this node is to be updated
		//past updation is left

		segtree[index]+=(ll)(right-left+1)*lazy[index];

		if(left!=right)
		{
			
			//this is not a leat node
			//pass the update info to children	

			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];

		}

		lazy[index]=0; // updation and passing are done

	}

	if(left>upr || right<upl)
	return ; //segment is completely outside the interval

	if(left>=upl && right <=upr)
	{

		//segment is completely inside the interval
		//current updation 

		segtree[index]+=(ll)(right-left+1)*(ll)val;
		
		if(left!=right)
		{

			//this is not a leat node
			//pass this info to their children

			lazy[2*index+1]+=val;
			lazy[2*index+2]+=val;			
	
		}

		return ;

	}

	int mid=(left+right)/2;

	update(left,mid,upl,upr,val,2*index+1);
	update(mid+1,right,upl,upr,val,2*index+2);

	segtree[index]=segtree[2*index+1]+segtree[2*index+2];

}

void build(int a[],int left,int right,int index)
{

	if(left==right)
	{
	
		segtree[index]=a[left];
		return ;

	}
	
	int mid=(left+right)/2;

	build(a,left,mid,2*index+1); //incase segtree is 0-base indexed
	build(a,mid+1,right,2*index+2);

	segtree[index]=segtree[2*index+1]+segtree[2*index+2];

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
			           printf("%lld\n",query(0,n-1,l-1,r-1,0));	
			           break;

		}

	}

	return 0;

}





















