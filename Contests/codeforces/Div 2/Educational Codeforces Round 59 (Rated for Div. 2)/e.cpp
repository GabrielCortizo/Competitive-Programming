#include<bits/stdc++.h>
using namespace std;
const int ms = 109;
typedef long long ll;
ll dp[ms][ms][ms],A[ms];
string str;

ll solve(int s, int e, int prefix){

  if(s == e)	return A[prefix + 1];
  else if(s > e) return 0;
  ll &resp = dp[s][e][prefix];
  if(resp != -1) return resp;
  resp = solve(s+1, e, 0) + A[prefix+1];
  
  for(int i = s+1;i<=e;i++){
  	if(str[i] == str[s]){
    	resp = max(resp, solve(s+1, i-1, 0) + solve(i, e, prefix + 1));
    }
  }
  
  return resp;
}

int main(){
	int n;	
  	memset(dp, -1,sizeof(dp));
  	cin >> n >> str;
  
  	for(int i = 1;i<=n;i++) cin >> A[i];
	cout<<solve(0,n-1, 0);


}
