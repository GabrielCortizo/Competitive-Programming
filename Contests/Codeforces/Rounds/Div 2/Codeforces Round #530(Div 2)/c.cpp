#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string str;
	int n, c = 0,me=0;
	bool b = 0;
	
	cin >>str>>n;
	str.push_back('#');
	for(auto ch:str){
		if(ch == '?'){
			me++;
		}else if(ch == '*'){
			me++;
			b = 1;
		}else if(ch !='#') c++;
	}
	
	if(n < c-me || (n>c && !b)){
		cout<<"Impossible";
	}
	else{
		
		if(n<c){
		
			int i = 0;	
			while(c!=n && i <str.size()-1){

				if(str[i+1] !='*' && str[i+1]!='?' && str[i] !='*' && str[i]!='?') cout<<str[i]; 
				else if(str[i+1] =='*' || str[i+1]=='?' ) c--;
				i++;

			}
			
			int ind = i;
			for(int j = ind;j<str.size()-1;j++) if(str[j]!='?'&& str[j]!='*') cout<<str[j];
			
			
			
		}else if(n == c){
		
			for(int i = 0;i<str.size()-1;i++) if(str[i]!='?' && str[i]!='*') cout<<str[i];
		}
		else {
			bool f = 0;
			
			for(int i = 0;i<str.size();i++){
				if(str[i] == '#') continue;
				if(str[i+1] == '*' && !f){
					for(int j = 0;j<=n-c;j++){
						cout<<str[i];
					}
					f = 1;
				}else if((str[i] !='*' && str[i]!='?')){
					cout<<str[i];
				}
				//cout<<str[i]<<endl;
			
			}
		}
		
	
	}

}
