#include<bits/stdc++.h>
using namespace std;
const int ms = 200;
int main(){
	int n,x,y;
	cin >> n >>x >>y;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	if(x > y) cout <<n;
	else{
		sort(v.begin(),v.end());
		auto it = upper_bound(v.begin(),v.end(),x);
		int s = it - v.begin();
		int soma = 0;
		soma += (s+1)/2;
		cout<<soma;
	}
	

}
