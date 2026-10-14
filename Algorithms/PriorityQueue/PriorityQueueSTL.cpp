#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct data{
	int a;
	char c;
	data(int a, char c): a(a), c(c){ } //constructor for struct in C++
	bool operator<(const data& rhs) const { 
		//custom comparator in case data is struct
		return a < rhs.a;
	}
};

int main() {
	
	priority_queue<data> pq;
	//data x = {42,'a'};
	pq.push(data(42,'a'));
	//x = {49,'b'};
	pq.push(data(49,'c'));
	//x = {53,'c'};
	pq.push(data(53,'b'));
	
	priority_queue<data> tmp = pq;
	while(!tmp.empty()){
		data pq_top = tmp.top();
		cout<<pq_top.a<<" "<<pq_top.c<<endl;
		tmp.pop();
	}
	
	//53 b
	//49 c
	//42 a
	
	return 0;
}
