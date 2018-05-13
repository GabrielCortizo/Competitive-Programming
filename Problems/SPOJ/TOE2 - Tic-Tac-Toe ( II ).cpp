#include<bits/stdc++.h>
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
#define x first
#define y second
using namespace std;

bool is_win(string config) {

	bool rows = 
		(config[0] != '.' && config[0] == config[1] && config[1] == config[2]) ||
		(config[3] != '.' && config[3] == config[4] && config[4] == config[5]) ||
		(config[6] != '.' && config[6] == config[7] && config[7] == config[8]);

	bool columns =
		(config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
		(config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
		(config[2] != '.' && config[2] == config[5] && config[5] == config[8]);

	bool diagonals =
		(config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
		(config[2] != '.' && config[2] == config[4] && config[4] == config[6]);

	return rows || columns || diagonals;
}

bool valid(string a){
	rep(i,0,a.size()){
		if(a[i] == '.') return false;
	}
	return true;
}	
	
int main(){
	string base,board="",a;
	string start,ans="no";
	int n;
	
	while(cin >> board && board!="end"){
		ans="invalid";
		start=".........";
		queue<pair<string,bool>> q;
		q.push(make_pair(start,1));
		while(q.size()){
				pair<string,bool> u = q.front();q.pop();
				
				if(u.x == board){
				
					if(	is_win(u.x) || valid(u.x) ){ans = "valid"; break;}

				}
				if(is_win(u.x) || valid(u.x))continue;

				rep(i,0,9){
					if((u.x)[i] == '.'){
						(u.x)[i] =(u.y)?'X':'O';
						if((u.x)[i] == board[i])
							q.push({ (u.x),1^(u.y) });
						(u.x)[i] = '.';
					}
				}
		}
		cout << ans<<"\n";
	}
	
	
}
