#include<bits/stdc++.h>
using namespace std;
const int ms = 23;
int n, low[ms], tin[ms], vis[ms];
vector<int> s, g[ms];
int cont, z;

void dfs(int v){

	low[v] = tin[v] = z++;
  vis[v] = 1;
  s.push_back(v);
  
  for(auto &it: g[v]){
  
  	if(!tin[it]){
    	dfs(it);
	  	low[v] = min(low[v], low[it]);	
  	}else if(vis[it])
  		low[v] = min(tin[it], low[v]);  
  }
  
  if(tin[v] == low[v]){
  	int u = -1;
  	do{
  		u = s.back();
  		vis[u] = 0;
  		s.pop_back();
  	}while(u!=v);
  	
  	cont++;
  }
}

void getSCC(){
	z = 1;
	cont = 0;
	memset(low,0,sizeof(low));
	memset(tin,0,sizeof(tin));
	memset(vis,0,sizeof(vis));
	s.clear();
	for(int i =0;i<n;i++)
		if(!tin[i])
			dfs(i);
}

int main(){

}
