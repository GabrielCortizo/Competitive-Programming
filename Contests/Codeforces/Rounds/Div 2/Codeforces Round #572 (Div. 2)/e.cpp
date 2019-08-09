#include<bits/stdc++.h>
#define int long long
using namespace std;
const int ms = 3e5+9;
int vet[ms], dp[ms];
map<int,int> mapa;
 
int n, k, p;
main(){
	cin >> n >> p >> k;
	for(int i = 0;i<n;i++) cin >> vet[i];
	
	for(int i = 0;i<n;i++){
		int a = vet[i];
		int val = ((((a%p)*(a%p))%p ) * (((a%p)*(a%p))%p)  )%p;
		val = ( (val - (k*a)%p)%p + p)%p;
		mapa[val]++;
	}
	
	long long soma = 0;
	
 
	for(auto it:mapa){
		if(it.second){
			soma += ((it.second)*(it.second-1))/2;
		}
	}
 
	cout<<soma;
 
}
