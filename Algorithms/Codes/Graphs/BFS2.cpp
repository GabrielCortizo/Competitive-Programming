#include<bits/stdc++.h>
#define rep(i,b,c) for(int i = (int)b;i<(int)c;i++)
#define x first
#define y second
using namespace std;
const int inf = 1e+9;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii>  graph;

void BFS2(int node, int depht){
	vi dist(graph.size()+1, inf);
	vi deepNodes;
	
	queue<int> q;
	q.push(node);
	dist[node] = 0;
	int sz = 1;
	for(int i = 0;i<depht && !q.empty(); i++, sz=q.size()){
		while(sz --){
			int u = q.front();
			q.pop();
			
			for(const auto &v :graph[u]){
				if(dist[v.x] == inf){
					dist[v.x] = dist[u] +1 ;
					if(i == depht-1){
						deepNodes.push_back(v.x);
					}
					q.push(v.x);
				}
			}	
		}
		if(depht -1 == i) break;
	}
}



int main(){

}
