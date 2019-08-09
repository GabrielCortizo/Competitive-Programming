#include<bits/stdc++.h>
using namespace std;
 
deque<int> dq;
vector<int> vet;
 
int main(){
	int n;
	cin >> n;
	vet.resize(n);
	for(int i =0;i<n;i++) cin >> vet[i];
	sort(vet.begin(),vet.end(),greater<int>());
	dq.push_back(vet[0]);
	for(int i = 1;i<n;i++){
		if(i&1) dq.push_back(vet[i]);
		else
			dq.push_front(vet[i]);
	}
	
	for(int i = 0;i<n;i++){
		vet[i] = dq.front();
		dq.pop_front();
	}
	bool b = 1;
	for(int i = 0;i<n;i++){
		int l = (i - 1 + n)%n;
		int r = (i+1)%n;
		if(vet[i] >= vet[l] + vet[r]) 
			b = 0;
	}
	
	if(!b) cout<<"NO";
	else{
		cout<<"YES\n";
		for(auto it:vet) cout<<it<<" ";
	}
	
 
}
