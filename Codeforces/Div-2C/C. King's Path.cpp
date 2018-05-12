#include<bits/stdc++.h>
#define rep(i,b,c) for(int i=(int)b;i<(int)c;i++)
#define x first
#define y second
#define all(v) v.begin(),v.end()
using namespace std;
typedef pair<int,int> ii;
int main(){
	set<ii> graph;
	map<ii,int> dist;
	int x0,x1,y0,y1,a,b,c,n;
	cin >> x0 >>y0 >>x1>>y1;

	cin >> n;
	
	rep(i,0,n){
		cin >> a >> b >> c;
		
		rep(j,b,c+1){graph.insert(ii(a,j));}
		
	}
	queue<ii> q;
	dist[ii(x0,y0)] = 0;
	q.push(ii(x0,y0));
	
	bool f = 0;
	while(!q.empty()&&!f){
	
		ii u = q.front();q.pop();
		rep(i,-1,2)
			rep(j,-1,2){
				if(!i&&!j) continue;
				int xt = u.x+i,yt=u.y+j;
				if(graph.count(ii(xt,yt)) && dist.count(ii(xt,yt))==0 ){q.push(ii(xt,yt));dist[ii(xt,yt)] = dist[ii(u.x,u.y)]+1;
				if(xt==x1 && yt==y1) { cout <<dist[ii(xt,yt)];return 0;}}
			}
	}
	cout << "-1";
	
}
