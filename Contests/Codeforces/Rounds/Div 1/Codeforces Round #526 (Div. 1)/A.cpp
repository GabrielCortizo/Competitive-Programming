/* Idea: Every vertice has at most 2 sons, dp[u] stores the maximum sum that we can have, if u is the father of all other ones,
So to calculate the maximum of every vertice we'll ask the following question, what is better to stay with the amount of gas we have so far or to
 or to conect the amount with we have with a new branch?
Every node works like a bound too, remember that doesn't matter where we start, cause if we start from a soon, it works just fine, cause he will use his
father as a branch, and remember to develop the sons first, it's better work with bottom up.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int ms = 300009;
ll w[ms];
typedef pair<int,int> ii;
vector<ii> g[ms];
ll maxi;
ll dp[ms];
void dfs(int v, int p){

	dp[v] = w[v];
	maxi = max(maxi, dp[v]);
	for(auto par: g[v]){
		int u = par.first;
		if(u == p) continue;
		dfs(u,v);
		dp[u] -= par.second;
		maxi = max(maxi, dp[u] + dp[v]);
		dp[v] = max(dp[v], dp[u] + w[v]);
	
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a,b,c,n;
	cin >> n;
	for(int i = 0;i<n;i++) cin >>w[i];
	for(int i = 0;i<n-1;i++){
		cin >>a>>b>>c;a--;b--;
		g[a].push_back(ii(b,c));
		g[b].push_back(ii(a,c));
	}
	dfs(0,-1);
	cout<<maxi;

}
