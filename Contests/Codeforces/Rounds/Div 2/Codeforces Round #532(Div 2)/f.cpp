#include<bits/stdc++.h>
using namespace std;
const int bs=25,ms=500009;
int table[bs], lst[bs], x[ms],l[ms],ans[ms];
vector<int> q[ms];

int main(){
	int n,m,a;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&x[i]);
	scanf("%d",&m);
	for(int i = 1;i<=m;i++) {
		scanf("%d %d",&l[i],&a);
		q[a].push_back(i);
	}
	
	for(int i = 1;i<=n;++i){
		int xi = x[i];
		int p = i;
		
		for(int j = 20;j>=0;--j){
			if(xi & (1<<j)){
				if(!table[j]){
				
					table[j] = xi;
					lst[j] = p;
					break;
					
				}else if(p > lst[j]){
					swap(xi,table[j]);
					swap(p,lst[j]);
				}
				xi^= table[j];
		
			}
		}	
		for(auto ind : q[i]){
			for(int j = 20;j>=0;--j){
				if(table[j] && l[ind] <=lst[j]) ans[ind] = max(ans[ind], ans[ind]^table[j]);
			
			}
		}
	}
	
	for(int i =1;i<=m;++i) printf("%d\n",ans[i]);

}
