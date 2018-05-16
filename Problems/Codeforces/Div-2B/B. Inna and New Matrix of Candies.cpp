#include<bits/stdc++.h>
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
using namespace std;

int main(){
	int n,m,l,r;
	char c;
	set<int> s;
	cin >> n >> m;
	bool f =0;
	rep(i,0,n){
		l = r = 0;
		rep(j,0,m){
			cin >> c;
			if(c == 'G')
				l = j;
			else if(c == 'S')
				r = j;
		}
		if(r<l) f = 1;
		else s.insert(r-l);
	}
	if(f)cout<<"-1";
	else cout <<s.size();
}
