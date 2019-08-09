#include<bits/stdc++.h>
using namespace std;
int a,b;
 
 
int main(){
	cin >> a >> b;
	int t = max(a,b);
	
	if(t == 0)
		cout<<"Not a moose";
	else{
		if(a == b)
			cout<<"Even "<<(a+b);
		else{
			cout<<"Odd "<<(2*t);
		
		}
		
	
	}
}
