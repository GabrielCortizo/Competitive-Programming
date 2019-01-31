#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int ms =  200 * 1000 + 13;

vector<ii> dp[ms];
vector<int> g[ms];
int a[ms],ans;
int n,m;

void dfs(int v, int p){
	vector<ii> ch;
	
	for(auto it : g[v]){
		if(it == p) continue;
		dfs(it,v);
		for(auto pii : dp[it])
			ch.push_back(pii);
	}
	sort(ch.begin(),ch.end());
	
	for(int i = 0;i<ch.size();i++){
		int j = i-1;
		int m1=0,m2=0;
		while(j+1 < ch.size() && ch[j+1].first == ch[i].first){
			++j;
			if( ch[j].second >= m1) {
				m2 = m1;
				m1 = ch[j].second;
			}
			else if(ch[j].second > m2) m2 =ch[j].second;
		
		}
		
		if(a[v]%ch[i].first == 0){
			ans = max(ans,m1+m2+1);
			dp[v].push_back({ch[i].first, m1+1});
			while(a[v]%ch[i].first == 0)
				a[v]/=ch[i].first;
		}else{
			ans = max(ans,m1);
		}
		i = j;
	}
	
	for(int i = 2;i*i<=a[v];++i){
		if(a[v]%i==0){
			dp[v].push_back({i,1});
			ans = max(ans,1);
			while(a[v]%i == 0){
				a[v]/=i;
			}
		}
	}
	
	if(a[v]>1) {
		dp[v].push_back({a[v],1});
		ans = max(ans,1);
	}
	


}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a1,b;
	
	cin >> n;
	
	for(int i = 0;i<n;i++) cin >> a[i];
	for(int i = 0;i<n-1;i++){
		cin >> a1>>b;
		a1--;b--;
		g[a1].push_back(b);
		g[b].push_back(a1);
	}
	
	ans = 0;
	dfs(0,-1);
	cout<<ans;


}
