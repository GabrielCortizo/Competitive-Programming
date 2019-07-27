#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll w,h,w1,h1,w2,h2;
	cin >> w >> h;
	cin >> w1>>h1>>w2>>h2;
	for(int i = h;i>=1;i--){
		//if(i != h1 && i != h2){
			w+=i;
		 if( i == h1){
			w-=w1;
		}else if(i == h2)
			w-=w2;
		
		if(w <=0) w = 0;
	}
	cout<<w<<"\n";
}
