#include<bits/stdc++.h>
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int inf = 1e+9;
vector<vii> graph;

void BFS(int node){
	vector<int> dist (graph.size()+1, inf);
	queue<int> q;
	q.push(node);
	dist[node] = 0;
		
	while(!q.empty()){
		int i = q.front();
		q.pop();
			
		for( const auto & u :graph[i]){
			if(dist[u.x] == inf){
				dist[u.x] = dist[i] + 1;
				q.push(u.x);
				
			}
				
		}
	}
}



int main(){}
