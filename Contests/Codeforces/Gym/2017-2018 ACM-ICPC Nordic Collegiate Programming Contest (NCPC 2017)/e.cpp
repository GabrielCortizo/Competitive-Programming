#include<bits/stdc++.h>
using namespace std;
const int ms = 509;
typedef pair<int,int> ii;
int dp[ms][ms];
int best[ms][ms];
int n,m;
bool isValid(int i, int j){
	return i>=0 and i<n and j>=0 and j<m;
 
}
 
int main(){
	int x,y;
	cin >> n >> m ;
	for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin >> dp[i][j];
	
	cin >> x >> y;x--;y--;
	memset(best, 0x3f,sizeof best);
	set<pair<int,ii>> s;
	
	s.insert({dp[x][y], {x,y}});
	best[x][y] = dp[x][y];
	
	
	
	long long soma = 0;
	while(s.size()){
		auto it = s.begin();
		int d = (*it).first;
		x = (*it).second.first;
		y = (*it).second.second;
		soma += max(0,-best[x][y]);
		
		s.erase(it);
		
		for(int i = -1;i<2;i++)
			for(int j = -1;j<2;j++){
				int xi = i+x;
				int yi =  y+j;
				if( (!i and !j) or !isValid(xi,yi)) continue;
				int val = max(d,dp[xi][yi]);
				
				if(val < best[xi][yi]){
					best[xi][yi] = val;
					auto it = s.find({best[xi][yi], {xi,yi}});
					if(it != s.end())
						s.erase(it);
					s.insert({val, {xi,yi}});
				}
			}
	}
	cout<<soma;
 
}
