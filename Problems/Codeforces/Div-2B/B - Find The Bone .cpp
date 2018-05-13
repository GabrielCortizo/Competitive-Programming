#include<bits/stdc++.h>
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
using namespace std;

bool hole[1000005];

int main(){
	int n,m,k,a,b,bone;
	cin >> n >> m >> k;
	rep(i,0,m){
		scanf("%d",&a);
		hole[a] = 1;
	}
	bool f = 0;
	bone = 1;
	if(hole[bone])f = 1;
	
	while(k--){
		scanf("%d %d",&a,&b);
		if(!f){
			if(a == bone){ bone = b;if(hole[bone])f = 1;}
			else if(b == bone) {bone = a;if(hole[bone])f = 1;}
		
		}
		
	
	}
	cout << bone;

}
