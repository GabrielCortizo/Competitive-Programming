#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
const int ms = 1e+5+9;
vector<iii> vet;
vector<iii> g[2];
int resp[ms];
int main(){
	int n,T,a,b;
	scanf("%d ",&T);
	while(T--){
		scanf("%d ",&n);
		g[0].clear();
		g[1].clear();
		vet.clear();
		for(int i = 0;i<n;i++){
			scanf("%d %d",&a,&b);
			vet.push_back(iii(ii(a,b),i));
		}
		sort(vet.begin(),vet.end());
		ii p = vet[0].first;
		g[0].push_back(vet[0]);
		int t = 0;
		for(int i = 1;i<n;i++){
			ii p2 = vet[i].first;
			if(p2.first >  p.second) t = 1-t;
			g[t].push_back(vet[i]);
			p.second = max(p.second,p2.second);
			p.first = min(p.first,p2.first);
		}
		if(g[0].size() == n) cout<<"-1\n";
		else{
			for(auto p1 : g[0]){
				resp[p1.second] = 1;
			}
			for(auto p1 : g[1]){
				resp[p1.second] = 2;
			}
			for(int i = 0;i<n;i++) printf("%d ",resp[i]);
			cout<<"\n";
		
		}
		
		 
		
	}
	
}
