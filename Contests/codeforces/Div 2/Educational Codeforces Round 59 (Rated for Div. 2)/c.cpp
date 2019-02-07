#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ms = 300000;
int n,k;
ll a[ms],maxi = 0;
string str;
int main(){

	cin >> n >> k;
	for(int i=  0;i<n;i++) cin >> a[i];
	cin >> str;
	char c = '#';
	priority_queue<int> pq;
	
	for(int i = 0;i<n;i++){
		if(c == '#'){
			c = str[i];
			pq.push(a[i]);
		
		}else if(c == str[i]){
			pq.push(a[i]);
		}
		if(c != str[i]){
			
			for(int j = 0;j<k && pq.size();j++){
				maxi += pq.top();
		//		cout<<pq.top()<<endl;
				pq.pop();
			
			}
			while(pq.size()) pq.pop();
			c = str[i];
			pq.push(a[i]);
			
		}
		
		if(i == n-1){
			
			for(int j = 0;j<k && pq.size();j++){
				maxi += pq.top();
				pq.pop();	
			}
		}
		
		
		
		
		
	}
	cout<<maxi<<endl;
	
}
