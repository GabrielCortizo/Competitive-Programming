#include<bits/stdc++.h>
using namespace std;
const int ms = 6000;
int v[ms], times[ms];
int start[ms],color[ms];
bool started[ms];
int main(){
	int n,k,c1 = 1;
	bool b = 0;
	cin >> n >>k;
	for(int i = 0;i<n;i++){
		cin >> v[i];
		if(times[v[i]] == 0 && c1 <= k){
			start[v[i]] = c1;
			c1++;
		}
		times[v[i]]++;
		if(times[v[i]]>k) b = 1;
	}
	if(b) cout<<"NO";
	else{
		cout<<"YES\n";
		for(int i = 0;i<n;i++){
		
			if(!started[v[i]] && start[v[i]]!=0){
				printf("%d ", start[v[i]]);
				started[v[i]] = 1;
				
			}else{
			
				color[v[i]]++;
				if(color[v[i]] == start[v[i]])
					color[v[i]]++;
				c1 = color[v[i]];
				printf("%d ",c1);
			}
		}
	
	}
}
