#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int ms = 1009;
char maze[ms][ms];
vector<ii> g[11];
int speed[101],n,p,m,sz[11];
int I[4] = {0,-1,1,0};
int J[4] = {1,0,0,-1};

bool isValid(int i, int j){	return ( (i>=0 && i<n) && (j>=0 && j<m) && maze[i][j] == '.');}


bool expansion(int x){

	queue<ii> q;
	
	for(auto it : g[x]) q.push(it);
	int d = 0;
	
	while(q.size() && d+1 <=speed[x] ){
	
		int s = q.size();
		d+=1;
		for(int s1 =0;s1<s;s1++){
			ii u = q.front();
			q.pop();
			
			for(int k = 0;k<4;k++){
				int i = u.first + I[k];
				int j = u.second + J[k];
				if(isValid(i,j)){
					
					maze[i][j] = '#';
					sz[x]++;
					q.push({i,j});
				}
			}	
		}
	}	
	
	g[x].clear();
	//cout<<q.size()<<endl;
	while(!q.empty()){
		g[x].push_back(q.front()),q.pop();}
	
	return g[x].size();
}

int main(){
	char c;
	scanf("%d %d %d",&n,&m,&p);

	for(int i = 1;i<=p;i++) scanf("%d",speed+i);
	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++) {
		scanf(" %c",&c);
		maze[i][j] = c;
		if(isdigit(c)){
			g[c-'0'].push_back({i,j});
			sz[c-'0'] ++;
		}
	}
	
	bool b = 1;
	
	while(b){
		
		b = 0;
		for(int i = 1;i<=p;i++)
			if(g[i].size())
				b|=expansion(i);
			
	}
	
	for(int i =1;i<=p;i++) 	printf("%d ",sz[i]);

}

