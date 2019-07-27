#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
const int ms = 1e+5 + 9;

vector<iii> g[ms];
vector<int> sol,ord;

int posi[ms];
bool visit[ms], cicle[ms];

int n,m;

bool dfs(int no, int k){
	if(cicle[no]) return 0;
	if(visit[no]) return 1;
	visit[no] = cicle[no] = 1;
	for(auto vu : g[no]){
		ii v = vu.first;
		if(v.second <= k) continue;
		if(!dfs(v.first, k)) return 0;
	}
	
	cicle[no] = 0;
	ord.push_back(no);
	return  1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c;
	cin >> n >> m;
	for(int i = 0;i<m;++i){
		cin >>a >>b >>c;
		g[a].push_back({{b,c},i+1});
	}
	
	int l=0,k,r=1e+9 + 9;
	while(r > l){
		ord.clear();
		memset(cicle,0,sizeof(cicle));
		memset(visit,0,sizeof(visit));
		k = (l+r)/2;
		bool bo = 1;
		for(int i = 1;i<=n;i++){
			if(!dfs(i,k)){
				bo = 0;
				break;
			}
		}
		if(bo)
			r = k;
		else l = k+1;
	}
	memset(cicle,0,sizeof(cicle));
	memset(visit,0,sizeof(visit));
	for(int i = 1;i<=n;i++) dfs(i,l);
	
	reverse(ord.begin(),ord.end());
	for(int i = 0;i<ord.size();i++)	posi[ord[i]] = i;
	for(int i = 1;i<=n;i++){
		for(auto jul : g[i]){
			ii ju = jul.first;
			if(ju.second <= l && posi[ju.first] < posi[i])
				sol.push_back(jul.second);
		}
	}
	sort(sol.begin(), sol.end());
	cout<<l <<" "<<sol.size()<<"\n";
	for(auto pos: sol) cout<< pos<<" ";		
	
}
