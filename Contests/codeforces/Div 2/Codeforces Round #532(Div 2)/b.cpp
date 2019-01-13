#include<bits/stdc++.h>
using namespace std;
const int ms = 109;
int vet[ms];
map<int,int> mapa;
int main(){
	int n,t;
	int a;
	cin >> n >>t;
	for(int i = 0;i<t;i++){
		cin >>a;
		mapa[a]++;
		if(mapa.size() == n) {
			cout<<1;
			for(int i = 1;i<=n;i++){
				int sz = mapa[i]--;
				if(sz == 1) mapa.erase(i);
			}
		}
		else cout<<0;
	}


}
