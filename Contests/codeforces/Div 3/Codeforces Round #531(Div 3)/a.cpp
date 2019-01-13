#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >>n;
	if((n%4 ==0) || (n&1)&&( ((n-1)/2)%2 == 1)) cout<<0;
	else{
		cout<<1<<"\n";
	}
	

}
