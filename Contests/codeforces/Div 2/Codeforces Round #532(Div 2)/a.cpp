#include<bits/stdc++.h>
using namespace std;
const int ms = 109;
int vet[ms];
int main(){
	int n,k;
	int s=0,e=0;
	cin >> n >>k;
	for(int i = 0;i<n;i++) {
		cin >> vet[i];
		if(vet[i] == -1) s++;
		else e++;	
	}
	int maxi = 0;
	for(int b = 0;b<n;b++){
		int s1 = s;
		int e1 = e;
		int ind = b;
		while(ind>=0){
			if(vet[ind] == -1) s1--;
			else e1--;
			ind-=k;
		}
		ind = b+k;
		while(ind<n){
			if(vet[ind] == -1) s1--;
			else e1--;
			ind+=k;
		}
		maxi = max(maxi,abs(s1-e1));		
	}
	cout<<maxi<<"\n";
}
