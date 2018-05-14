#include<bits/stdc++.h>
#define x first
#define y second
#define rep(i,b,c) for(int i = (int)b;i<(int)c;i++)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> graph;
vi visited;

rep(i,0,n){
    if(!visited[n])  DFS(n);
}
void DFS(int node){
 ii u;
 visited[node] = 1;
 
 for(auto u:graph[node]){
 if(!visited[u.x])
 DFS(u.x);
 }
}

