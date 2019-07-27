#include<bits/stdc++.h>
using namespace std;
int main(){
	int q,n;
	string str;
	cin >> q;
	while(q--){
		cin >> n;
		cin >>str;
		if(n == 2 && str[0] >= str[1]) cout<<"NO"<<endl;
		else{
			cout<<"YES\n";
			cout<<2<<endl;
			cout<< str[0] <<" "<<str.substr(1)<<endl;
		
		}
		
	
	}


}
