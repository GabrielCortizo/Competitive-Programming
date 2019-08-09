#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int ms = 1e5+9;
ii vet[ms];
 
multiset<ii> s;
int n,m;
int a,b;
 
 
 
int main(){
	cin >> n >> m;
	while(m--){
		cin >> a>> b;
		if(a != 1){
			if(vet[a] < vet[1]){
				auto it = s.find(vet[a]);
				vet[a].first--;
				vet[a].second+=b;
				s.erase(it);
				s.insert(vet[a]);
			}else {
				vet[a].first--;
				vet[a].second += b;
				if(vet[a] < vet[1])
					s.insert(vet[a]);
			}
			
	}else{
		vet[1].first--;
		vet[1].second+=b;
		s.erase(s.lower_bound(vet[1]), s.end());
		}	
		
		/*cout<<s.size()<<endl;
			for(auto it:s)
				cout<<it.first<<" "<<it.second<<endl;*/
	cout<<(s.size()+1)<<endl;
	}
}
