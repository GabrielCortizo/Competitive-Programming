#include<bits/stdc++.h>
using namespace std;
const int ms = 509;
typedef pair<double, int> di;
typedef pair<double, double> dd;
vector<string> name;
vector<dd> a_b;
vector<di> vdi;
 
double mini = 0x3f3f3f3f3f3f3f3f, a,b, val;
int n, c;
bool be;
 
string str;
priority_queue<di, vector<di>, greater<di>> pq;
 
int main(){
	string str;
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> str >> a >> b;
		a_b.push_back({a,b});
		name.push_back(str);
		pq.push({b, i});
	}
	
	vector<di> ans, vals;
	
	for(int i = 0;i<n;i++){
		val = a_b[i].first;
		vals.clear();
		bool be = 0;
		
		while(vals.size()< 3){
			
			auto it = pq.top();
			pq.pop();
			if(it.second == i){
				be = 1;
			}else{
				vals.push_back(it);
				val += it.first;
			}
		}
		if(val < mini){
			mini = val;
			ans = vals;
			ans.push_back({i,i});
		}
		
		while(vals.size()){
			pq.push(vals.back());
			vals.pop_back();
		}
		if(be)
			pq.push({a_b[i].second, i});
	}
	
	cout<<mini<<endl;
	for(int i = 3;i>=0;i--){
		
		cout<<name[ans[i].second]<<endl;
	}
 
}
