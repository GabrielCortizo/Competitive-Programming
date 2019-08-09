#include<bits/stdc++.h>
using namespace std;
int a,b;
int n;
const int ms = 1e5+9;
int ind[ms];
 
 
int main(){
	cin >> n;
	for(int i = 0;i<n-1;i++){
		cin >> a >> b;
		ind[a]++;
		ind[b]++;
	}
	b = 1;
	for(int i = 1;i<=n;i++){
		if(ind[i] == 2)
			b = 0;
	}
	if(b) cout<<"YES";
	else cout<<"NO";
 
 
}
