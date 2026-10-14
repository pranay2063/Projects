#include<bits/stdc++.h>

using namespace std;

void runningMedian(int a[], int n){

	priority_queue<int> maxheap; //stores minimum half of elements
	priority_queue<int, vector<int>, greater<int> > minheap; //stores maximum half of elements

	minheap.push(a[0]);
	cout<<"Median after processing 1 element : "<<minheap.top()<<endl;

	for(int i = 1; i < n; ++i){

		if(a[i] > minheap.top()) minheap.push(a[i]);
		else maxheap.push(a[i]);

		int diff = minheap.size() - maxheap.size();
		if(diff > 1){
			//balance both the heaps by shifting one element from minheap to maxheap
			int top = minheap.top();
			minheap.pop();
			maxheap.push(top);
		}
		else if(diff < -1){
			//balance both the heaps by shifting one element from maxheap to minheap
			int top = maxheap.top();
			maxheap.pop();
			minheap.push(top);
		}
		
		//cout<<minheap.size()<<" "<<maxheap.size()<<endl;

		if(minheap.size() == maxheap.size()){
			cout<<"Median after processing "<<(i+1)<<" elements : "<<(minheap.top()+maxheap.top())/2.0<<endl;
		}
		else if(minheap.size() > maxheap.size())
			cout<<"Median after processing "<<(i+1)<<" elements : "<<minheap.top()<<endl;

			else cout<<"Median after processing "<<(i+1)<<" elements : "<<maxheap.top()<<endl; 

	}

}

int main(){


	int n;
	cin>>n;

	int a[n];
	for(int i = 0; i < n; ++i)
		cin>>a[i];

	runningMedian(a, n); 
  	//Time complexity : O(NlogN)
  	//Space complexity : O(N)

	return 0;

}
