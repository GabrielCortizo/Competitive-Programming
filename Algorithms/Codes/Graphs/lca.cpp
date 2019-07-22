#include<bits/stdc++.h>
using namespace std;
const int ms = 450025, mlg = 20;

int par[ms][mlg+1], lvl[ms],n;
vector<int> g[ms];

void dfs(int v, int p,int l=0){  //dfs(root, -1)

  par[v][0] = p;
  lvl[v] = l;
  
  for(auto &it: g[v]){
  
    	if(it == p) continue;
    	dfs(it,v,l+1);   	
  }
}

void init(){
	memset(par,-1,sizeof(par));
}

void table(){
	for(int i = 1;i<=mlg;i++)
		for(int j = 0;j<n;j++)
      		if(par[j][i-1]!= -1)
      			par[j][i] = par[par[j][i-1]][i-1];

}

int lca(int a, int b){
  if(lvl[a] < lvl[b])
    swap(a,b);
  for(int i = mlg;i>=0;i--){
    if(par[a][i]!= -1 and lvl[par[a][i]] >= lvl[b]){
      a = par[a][i];  
    }
  }
  
  if(a == b)
  	return a;
  
  for(int i =mlg;i>=0;i--){
    if(par[a][i] != par[b][i] and par[a][i]!= -1 ){
    	a = par[a][i];
    	b = par[b][i];  
    }
  }
  return par[a][0];
}

int main(){}
