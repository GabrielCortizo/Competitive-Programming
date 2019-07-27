#include<bits/stdc++.h>
using namespace std;

string str;
int main(){
	int a=0,b=0,c=0,d=0;
	int s = 0;
	cin >> str;
	a = str.find('[');
	b = str.rfind(']');
	c = str.find(':',a);
	d = str.rfind(':',b);
	bool f = ( a<0 || b<0 || c<0 || d<0);
	
	f |= (a>b || c>=d);
	if(f){
		cout<<-1;
	} else{
		for(int i = c+1;i<d;i++) if(str[i]=='|') s++;
		s+=4;
		cout<<s<<"\n";
	
	}

}
