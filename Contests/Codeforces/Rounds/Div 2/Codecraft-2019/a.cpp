#include<bits/stdc++.h>
using namespace std;
string str1,str2;
char v[] = {'a','e','i','o','u'};
bool vocal(char c){
	for(int i = 0;i<5;i++) if(c == v[i]) return true;
	return false;

}

int main(){
	cin >> str1 >> str2;
	if(str1.size() != str2.size()){
		 cout<<"No";
	return 0;
	}
	else{
		for(int i = 0;i<str1.size();i++){
			bool b = vocal(str1[i]);
			bool b2 = vocal(str2[i]);
			if((b && !b2) || (!b && b2)){
				cout<<"No";
				return 0;
			} 
	
			
		}
	
	}
	cout<<"Yes";
	


}
