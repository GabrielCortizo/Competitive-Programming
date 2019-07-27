#include<bits/stdc++.h>
using namespace std;const int ms = 401;
long long ans = 0; 
int n, m,s,b,d,c,memo[ms][ms][ms],a[ms],i,j,k,opt;

int main(){
	 scanf("%d %d",&n,&m);
	 for(i = 0;i<n;i++) scanf("%d",a + i);
	 
	 for(i= 0;i<n;i++) for(j=i;j<n;j++) memo[i][j][0] = (a[j]-a[i]);
	 
	 
	 for(k=1;k<=n;k++) for(i = 0;i<n;i++) for(j = i,opt=i;j<n;j++) {
	 	while(opt<j && max(a[j]-a[opt],memo[i][opt][k-1]) >= max(a[j]- a[opt+1],memo[i][opt+1][k-1])) opt++;
	 	memo[i][j][k] = max(a[j]-a[opt], memo[i][opt][k-1]);		
	 }
	
	for(;m--;){
		scanf("%d%d%d%d",&s,&b,&c,&d);
		s--;b--;
		ans = max(ans, 1LL*memo[s][b][d]*c);
	}
	printf("%lld",ans);
}
