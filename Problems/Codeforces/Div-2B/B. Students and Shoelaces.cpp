#include<bits/stdc++.h>
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> graph;
vi indegree;

int sol(){
	queue<int> q;
	int cont = 0;
	rep(i,1,indegree.size()){
		if(indegree[i] == 1) q.push(i);
	}
	
	while(!q.empty()){
		cont ++;
		int sz = q.size();
		while(sz--){
			int v = q.front();
			q.pop();
			indegree[v] --;
			
			rep(i,0,graph[v].size()){
				ii u = graph[v][i];
				indegree[u.x]--;
				
			}
			
		}
		rep(i,1,indegree.size()){
			if(indegree[i] == 1) q.push(i);
		}
	
	}
	return cont;
}


int main(){
	int n, m, a, b;
	cin >> n >> m;
	graph.resize(n+1);
	indegree.assign(n+1, 0);
	rep(i,0,m){
		cin >> a >> b;
		graph[a].push_back(ii(b,0));
		graph[b].push_back(ii(a,0));
		indegree[a] ++ ;
		indegree[b] ++;
	}
	cout <<sol();
	

}
