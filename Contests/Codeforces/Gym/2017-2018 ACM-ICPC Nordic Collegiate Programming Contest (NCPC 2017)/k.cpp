#include<bits/stdc++.h>
#define int long long 
using namespace std;
 
int b, n, e, sb, sn, se;
int bo;
vector<int> vet;
 
 
bool p(int val){
 
	int x1 = b, x2 = n, x3 = e;
	int c=0;
	for(int i = 0;i<bo;i++){
	
		int c = vet[i];
		if(x1 >= 2 and (sb*2)*c >= val){
			x1-=2;
		}else if(x1 and x2 and (sb+sn)*c >= val){
			x1--;
			x2--;
		}else if((sb + se) >= 2*sn and x2 >= 2 and (2*sn)*c >= val){
			x2-=2;
		}else if( (sb + se) <= 2*sn and x1 and x3 and(sb+se)*c >= val){
			x1--;
			x3--;
		}else if( x2 >= 2 and (2*sn)*c >= val){
			x2-=2;
		}else if(x1 and x3 and (sb+se)*c >= val){
			x1--;
			x3--;
		}else if(x2 and x3 and (sn+se)*c >= val){
			x2--;
			x3--;
		}else if(x3 >=2 and (2*se)*c >= val){
			x3-=2;
		}else{
		
			return false;
		}
	
	}
	return true;
 
}
 
main(){
	cin >> b >> n >> e;
	cin >> sb >> sn >> se;
	bo = (b+n+e)/2;
	vet.resize(bo);
	for(int i= 0;i<bo;i++)
		cin >> vet[i];
 
	int l = 0, r = 1e10,m;
	sort(vet.begin(),vet.end());
	while(r-l > 1){
		m = (l+r)/2;
		if(p(m))
			l = m;
		else
			r = m;	
	}
	
	cout<<l<<endl;
 
}
