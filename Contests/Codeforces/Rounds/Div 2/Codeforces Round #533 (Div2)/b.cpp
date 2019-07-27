#include<bits/stdc++.h>
using namespace std;
vector<string> g[100];

int main(){
	int n,k;
	string str,str1;
	cin >>n >> k;
	char c;
	str1 = "";
	for(int i = 0;i<n;i++){
		cin >>c;
		
		if(str1.size() == 0 || str1.back() == c){
			str1.push_back(c);
		}else{
		
			g[str1.back()-'a'].push_back(str1);
			str1.clear();
			str1.push_back(c);	
		
		}
		
		if(i == n-1){
			//cout<<str1<<endl;
			g[str1.back()-'a'].push_back(str1);
		
		}
	}
	int maxi = 0;
	
	for(int i = 0;i<26;i++){
		int soma = 0;
		for(auto j: g[i]){
			if(j.size()/k){
				soma +=j.size()/k;
				
			}
		}
		maxi = max(maxi,soma);
	}
	
	cout<<maxi<<endl;
	
	

}
