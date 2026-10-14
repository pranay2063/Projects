#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct data{
	string str;
	data(string strVal): str(strVal){ }
};

int main() {
	
	priority_queue<string> pq;
	pq.push("Iron man");
	pq.push("Captain America");
	pq.push("Thor");
	pq.push("Hulk");
	pq.push("Black Panther");
	
	priority_queue<string> tmp = pq;
	while(!tmp.empty()){
		data pq_top = tmp.top();
		cout<<pq_top.str<<endl;
		tmp.pop();
	}
	
	//Thor
	//Iron man
	//Hulk
	//Captain America
	//Black Panther
	
	return 0;
}
