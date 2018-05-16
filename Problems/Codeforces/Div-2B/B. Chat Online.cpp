#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
using namespace std;
bool ans[1001];
int a[1001],b[1001];
int main(){
	int p, q, l, r, c,d;
	int cont = 0;
	cin >> p >> q >>l >> r;
	rep(i,0,p){cin >> a[i] >> b[i];}
	
	rep(i,0,q){
		
		cin >> c >> d;
		rep(j,0,p){
			int x = a[j] - d; 
			int y = b[j] - c;
			
			if( x< l || y > r) continue;
			for(int k = max(x,l); k<=min(r,y);k++){
				if(!ans[k])
					{ans[k] = 1;cont++;}
			}	
		
		}
	}
	cout << cont;
	
}
