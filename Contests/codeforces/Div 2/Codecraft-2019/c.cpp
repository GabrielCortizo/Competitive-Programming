#include<bits/stdc++.h>
using namespace std;
const int ms = (1<<30) + 9;
typedef long long int ll;

vector<int> vetor;
ll A, B;


ll query(int x, int y){
	
	auto it = upper_bound(vetor.begin(), vetor.end(), x);
	auto it2 = lower_bound(vetor.begin(), vetor.end(), y);
	//cout<<x <<" "<<y<<" "<<(it-it2)<<endl;
	
	return it - it2;
	
	
}

ll calc(double x, double sz){
	if(x == 0) return A;
	else return x*sz*B;
}

typedef pair<int,int> ii;
map<pair<int,int>, ll > mapa; 

ll solve(ll l, ll r){

	if(l > r) return 1000000000;
	
	ll num =query(r, l);
	if(num == 0) return 0;
	ll sz = r-l+1;
	
	if(l == r) return calc(num, 1);
	
	int m = (l+r)/2;
	ll resp = solve(l, m) + solve(m+1,r);
	
	resp = min(resp, calc(num, sz));
	return resp;

}

int main(){

	int n,k,v1;
	cin >> n >> k >> A >> B;
	
	for(int i = 0;i<k;i++){
		cin >> v1;
		vetor.push_back(v1);
	} 
	sort(vetor.begin(),vetor.end());
	cout<<solve(1, 1<<n);

}
