#include<bits/stdc++.h>
using namespace std;
 
string str;
 
int main(){
	int n,a=0,b=0;
	cin >> n;
	cin >> str;
	for(int i = 0;i<str.size();i++){
		if(str[i] == '1')
			a++;
		else
			b++;
	}
	
	if(a!=b) {
		cout<<1<<endl;
		cout<<str;
	}
	else{
		cout<<2<<endl;
		cout<<str[0]<<" ";
		cout<<str.substr(1);
	}
	
}
