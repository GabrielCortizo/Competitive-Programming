#include<bits/stdc++.h>
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
using namespace std;
int vet[100004];
bool isValid(int i,int j,int k){
	if(i<j+k && j< i+k && k<i+j)
		return true;
	return false;
}

int main(){
	int n;
	cin >> n;
	rep(i,0,n)cin >> vet[i];
	bool f = 0;
	sort(vet,vet+n);
	rep(i,1,n-1){
		if(isValid(vet[i-1],vet[i],vet[i+1])){f = 1;break;}		
	}
	if(f == 1) cout << "YES";
	else cout << "NO";
}
