#include<bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
#define clr(v,val) memset(v,val,sizeof(val))
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi indegree, visited, ordem;
vector<vii> graph;

bool Toposort(){
	queue<int> q;
	rep(i,1,indegree.size()){
		if(indegree[i] == 0)	q.push(i);
	}
	
	while(!q.empty()){
		int u = q.front();
		ordem.push_back(u);
		q.pop();
		rep(i,0,graph[u].size()){
			ii v = graph[u][i];
			indegree[v.x] --;
			if(indegree[v.x] == 0)	
				q.push(v.x);
		}
	}
	rep(i,0,indegree.size()){
		if(indegree[i] !=0)
			return false;
	}
	return true;
}

