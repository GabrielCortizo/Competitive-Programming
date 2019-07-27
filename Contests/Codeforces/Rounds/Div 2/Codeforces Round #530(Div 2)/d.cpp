#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ms = 500099;
ll peso[ms],soma[ms];
bool v[ms];
vector<int> g[ms];
bool dfs(int node){
	for(auto ve : g[node]){
		if(soma[ve] == -1){
			ll mini = g[ve].size() == 0? -1:1e+9;
			for(int no_ve : g[ve]){
				mini = min(mini,soma[no_ve]);
			}
			soma[ve] = (mini == -1)?soma[node]:mini;
		}
		
		peso[ve] = soma[ve] - soma[node];
		
		if(soma[ve] < soma[node] || !dfs(ve)) return false;
	}
	
	return true;
}


int main(){
	int n,p;
	ll s = 0;
	cin >>n;
	
	for(int i = 1;i<n;i++){
		cin >> p;p--;
		g[p].push_back(i);
	}
	
	for(int i = 0;i<n;i++) cin >> soma[i];
	peso[0] = soma[0];
	
	if(!dfs(0)) s = -1;
	else	for(int i =0;i<n;i++) s+=peso[i];
	
	cout<<s;
}
