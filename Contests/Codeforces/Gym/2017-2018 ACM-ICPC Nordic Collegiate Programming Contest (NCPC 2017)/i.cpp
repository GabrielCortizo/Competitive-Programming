#include<bits/stdc++.h>
using namespace std;
const int ms = 509;
 
int n;
map<string,int> mapa;
map<int,string> mapa2;
 
vector<int> g[ms];
 
const int inf = 0x3f3f3f3f;
int d[ms];
int p[ms];
 
 
int bfs(int v){
	queue<int> q;
	q.push(v);
	memset(d, 0x3f, sizeof d);
	p[v] = -1;
	d[v] = 0;
	bool b = 0;
	while(q.size()){
		int ve = q.front();
		q.pop();
		
		for(auto &it: g[ve]){
		
			if(d[it] == inf or it == v){
				d[it] = d[ve] + 1;
				p[it] = ve;
				if(it == v)
					return d[v];
				q.push(it);
			}
		}
	}
	
	return inf;
 
}
 
 
int main(){
	string str, c;
	int cont = 0, t;
 
	cin >> n;
	
	for(int i = 0;i<n;i++){
		cin >> c;
 
		mapa[c] = cont;
		mapa2[cont++] = c;
	}
 
	for(int i = 0;i<n;i++){
		cin >> c >> t;
		
		while(t--){
			cin >> str;
			getline(cin,str);
			string s2 = "";
			
			for(int i= 0;i<str.size();i++){
		
				if(str[i] == ' ')
					continue;
				else if(str[i] == ',' or i == str.size()-1){
					if(i == str.size()-1)
					 s2.push_back(str[i]);
					
					int u = mapa[s2];
					int v = mapa[c];
					g[u].push_back(v);
					s2 = "";
				}else
					s2.push_back(str[i]); 
				
			
			
			}
		
		}
	}
	
	int maxi = inf;
	int ve =0;
	
	for(int i = 0;i<n;i++){
		int val = bfs(i);
		
		if(val < maxi){
			maxi = val;
			ve = i; 
		}
	}
	bfs(ve);
 
	
	vector<int> ans;
	if(maxi == inf)
		cout<<"SHIP IT";
	else{
		//ans.push_back(p[ve]);
		int v = ve;
		ans.push_back(ve);
		
		while(p[ve] != v){
			//cout<<ve<<endl;
			ve = p[ve];
			ans.push_back(ve);
		}
		//reverse(ans.begin(),ans.end());
		for(auto &it:ans) cout<<mapa2[it]<<" ";
	
	}
}
