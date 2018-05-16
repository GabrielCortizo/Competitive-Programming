#include<bits/stdc++.h>
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
using namespace std;

int main(){
	set<int> s;
	int n,v;
	cin >> n;
	rep(i,0,n){
		cin >> v; s.insert(v);
	}
	
	if(s.size() > 3){
		printf("NO");
	}else if(s.size() == 3){
		auto it = s.begin();
	
		auto a = *it++;
		auto b = *it++;
		auto c = *it;
		
		if((b-a == c-b))
			printf("YES");
		else printf("NO");
	
	}else if(s.size() <= 2){
		cout << "YES";
	
	}else{
		cout <<"YES";}
}
