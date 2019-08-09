#include<bits/stdc++.h>
using namespace std;
queue<int> q;
const int ms = 1<<20;
 
int d[ms];
string str;
 
int main(){
	int n,k;
	memset(d, 0x3f, sizeof(d));
	cin >> n >> k;
	for(int i = 0;i<n;i++){
		int u = 0;
		cin >> str;
		for(int i = 0;i<k;i++){
			u|=(1<<(i))*(str[i] == '1');
		
		}
		
		d[u] = 0;
		q.push(u);
	}
	
	int best = 0, u,v;
	
	while(q.size()){
		best = q.front();
		q.pop();
		u = best;
		
		for(int i = 0;i<k;i++){
			v = best^(1<<i);
			if(d[u] + 1 < d[v]){
				d[v] = d[u]+1;
				q.push(v);
			}
		
		}
	}
	
	for(int i = 0;i<k;i++){
		if(best&(1<<i)) cout<<1;
		else cout<<0;
	
	}
 
 
}
