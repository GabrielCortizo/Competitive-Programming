#include<bits/stdc++.h>
const int ms = 3e5 + 19;
using namespace std;
string per = "ACGT";
int n,m,ans = ms;
string c[ms], cer[ms];
bool w[ms];
int main(){
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> c[i];
		cer[i] = c[i];
	}
	
	do {
	
		int cur = 0;
		for(int i = 0; i < n; i++){
			int c1 = 0, c2 = 0;
			for(int j = 0; j < m; j++){
				c1 += per[ (i & 1)*2 + (j & 1)]  != c[i][j];
				c2 += per[ (i & 1)*2 + !(j & 1)] != c[i][j];
			
			}
			w[i]= c1 < c2;
			cur+= min(c1,c2);
		}
		if(cur < ans){
			for(int i = 0; i<n;i++){
				for(int j = 0;j<m;j++){
					cer[i][j] = w[i]? per[ (i & 1)*2 + (j & 1)]:per[ (i & 1)*2 + !(j & 1)];
				}
			}
		
		
		
			ans = cur;
		}
		
		cur = 0;
		for(int i = 0; i<m;i++){
			int c1 = 0, c2 =0;
			for(int j = 0; j< n; j++){
				c1 += per[ (i & 1)*2 + (j & 1)] != c[j][i];
				c2 += per[ (i & 1)*2 + !(j & 1)] != c[j][i];
			}
			w[i] = c1 < c2;
			cur += min(c1,c2);
		
		}
		
		if(cur < ans){
			for(int i = 0; i<m;i++)
				for(int j = 0;j<n;j++)
					cer[j][i] = w[i]?per[ (i & 1)*2 + (j & 1)]:per[ (i & 1)*2 + !(j & 1)];
			
		
			ans = cur;
		}
		
	//cout<<ans<<"\n";
	
	
	}while(next_permutation(per.begin(),per.end()));
	
	for(int i = 0;i<n;i++) cout <<cer[i]<<"\n";


}
