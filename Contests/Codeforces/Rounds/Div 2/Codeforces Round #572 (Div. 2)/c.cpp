#include<bits/stdc++.h>
using namespace std;
const int ms = 1e5+9;
 
int S[ms];
int vet[ms];
 
int n;
 
 
int main(){
	int l, r;
	cin >> n;
	for(int i = 0;i<n;i++) cin >> vet[i];
	int q;
	cin >> q;
	
	for(int i = 0;i<n;i++){
		S[i+1] = S[i] + vet[i];
	}
	
	while(q--){
		cin >> l >> r;
		int val = S[r] - S[l-1];
		cout<<(val/10)<<endl;
	}
	
	
	
 
}
