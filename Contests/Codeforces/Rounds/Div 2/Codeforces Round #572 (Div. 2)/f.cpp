#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int ms = 1e3+9, M = 998244353;
int dp[ms][ms], n, k, arr[ms], l[ms], pre[ms];
 
int solve(int x){
	//memset(dp, 0, sizeof(dp));
	for(int i =0;i<ms;i++) dp[i][0] = 0;
	dp[0][0] = 1;
	//memset(l,0,sizeof l);
	l[0] = 1;
	for(int i = 1;i<=n;i++){
		l[i] = l[i-1];
		while(arr[i] - arr[l[i]] >= x) l[i]++;
	}
	
	for(int i = 0;i<k;i++){
		pre[0]= dp[i][0];
		for(int j =1;j<=n;j++){
			pre[j] = (pre[j-1] + dp[i][j])%M;
		}
		
		for(int j =1;j<=n;j++)
			dp[i+1][j] = pre[l[j]-1];
	}
	
	int ans = 0;
	for(int j = 1;j<=n;j++)
		ans = (ans + dp[k][j])%M;
	return ans;
 
 
}
 
main(){
	scanf("%lld %lld",&n,&k);
	for(int i =1;i<=n;i++) scanf("%lld",&arr[i]); 
	sort(arr+1,arr+n+1);
	int sol = 0;
	
	for(int i = 1;i<=arr[n]/(k-1);i++){
		sol = (sol + solve(i))%M;
	}
	cout<<sol;
 
 
}
