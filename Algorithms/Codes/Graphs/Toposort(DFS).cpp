#include<bits/stdc++.h>
#define rep(i,b,c) for(int i = (int)b;i<(int)c;i++)
#define all(v) v.begin(),v.end()
#define x first
#define y second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> graph;
vector<bool> visited;
vi ordem;


void modified_dfs(int node){
	visited[node] = 1;
	for(auto u :graph[node]){
		if(!visited[u.x])
			modified_dfs(u.x);
	}
	ordem.push_back(node);
}

void toposort(){
	rep(i,0,graph.size()){
		if(visited[i] == 0){
			modified_dfs(i);
		}
	}
}

