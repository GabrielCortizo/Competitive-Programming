#include<bits/stdc++.h>
#define rep(i,b,c) for(int i = (int)b;i<(int)c;i++)
#define x first
#define y second
using namespace std;
bool fun(const pair<int,string> &a, const pair<int,string> &b){
	if(a.x!=b.x) return a.x > b.x;
	return a.y < b.y;

}

int main(){
	int t,n,s,d,cont;
	string a,b;
	map<string,vector<string> > graph;
	vector<pair<int,string>> ans;
	
	cin >> t;
	
	rep(re,0,t){
		ans.clear();
		graph.clear();
		cin >> n >> d;
		rep(i,0,n){
			cin >> a >> s;
			rep(j,0,s){cin >>b;graph[a].push_back(b);}
		
		}
		
		
		for(const auto u : graph){
			//  cout << u.x<<"-"<<endl<<endl;;
				map<string,bool> visit;
				cont = 0;
				queue<string> q;
				vector<string> vet;
				q.push(u.x);
				int size =1;
				visit[u.x] = 1;
			for(int i = 0;i<d , !q.empty();i++,size = q.size()){
					
					while(size--){
						string v = q.front();q.pop();
						if(graph.count(v) == 0) continue;
						visit[v] = 1;
						vet = graph[v];
						
						rep(k,0,vet.size()){
						//	cout << vet[k]<<" "<<vet.size()<<" "<<v<<endl;;
							if(visit.count(vet[k]) == 0){
								q.push(vet[k]);
								visit[vet[k]] = 1;
								if(i == d-1){ cont++;}
						
							}
					
						}
				//		cout <<endl;
				}
			}
		//	cout <<" "<<endl;
				if(cont>0) { ans.push_back(make_pair(cont,u.x));}
		}
		cout << "Tree "<<re+1<<":\n";
		int low = 0;
		int it = 0;
		sort(ans.begin(),ans.end(),fun);
		rep(i,0,min((int)ans.size(),3)){
			if(ans[i].x){
				cout << ans[i].y <<" "<<ans[i].x<<endl;
				low = ans[i].x;
			}
		}
		if(ans.size()>3){
			rep(i,3,ans.size()){
					if(ans[i].x == low){
					cout << ans[i].y <<" "<<ans[i].x<<endl;
		
					}else break;
				}
		
		}
		
	}
}
