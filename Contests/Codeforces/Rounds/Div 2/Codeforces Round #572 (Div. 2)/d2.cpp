#include<bits/stdc++.h>
using namespace std;
const int ms = 1e3+9;
typedef pair<int,pair<int,int>> iii;
 
vector<int> g[ms];
vector<iii> edges, sol;
int indegree[ms];
 
int n, a, b, c;
 
bool isValid(){
	for(int i = 1;i<=n;i++) if(g[i].size() == 2) 	return false;
	return true;
}
 
int findLeaf(int v, int p){
	
	for(auto it: g[v])
		if(it!= p)
			return findLeaf(it, v);
	return v;
}
 
void addTree(int u, int v, int c){
	vector<int> vet;
	
	if(g[v].size() == 1){
		sol.push_back({c,{u,v}});
	}else{
		for(auto &it: g[v]){
			if(it!=u)
				vet.push_back(findLeaf(it, v));
			if(vet.size() == 2)
				break;		
		}
		
		int u1 = findLeaf(u, v);
		sol.push_back({c/2,{u1, vet[0]}});
		sol.push_back({c/2,{u1, vet[1]}});
		sol.push_back({-c/2,{vet[0], vet[1]}});		
	}
 
}
 
void mountTree(iii &a){
	int c = a.first, u, v;
	tie(u,v) = a.second;
	if(g[v].size() == 1) swap(u,v);
	addTree(u,v,c);
	if(g[v].size() == 1 or g[u].size() == 1) return;
	v = (g[u][0] ==v)? g[u][1]:g[u][0];
	addTree(v,u,-c);
 
}
 
 
 
int main(){
	cin >> n;
	for(int i = 1;i<n;i++){
		cin >> a>> b>> c;
		edges.push_back({c,{a,b}});
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	if(!isValid()){
		cout<<"NO";
		return 0;	
	}
	cout<<"YES\n";
	for(auto &it: edges){
		mountTree(it);
	}
	cout<<sol.size()<<endl;
	for(auto &it:sol){
		cout<<it.second.first<<" "<<it.second.second<<" "<<it.first<<endl;
	}
	
 
}
