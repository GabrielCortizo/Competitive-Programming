#include<bits/stdc++.h>
using namespace std;
const int ms = 1e+5 + 9;
vector<double> vet;
vector<int> changes;
double soma = 0,k;
int n,m;

int main(){
	
	cin >> n >> k >> m;
	vet.resize(n);
	changes.assign(n,0);
	for(int i = 0;i<n;i++) {
		scanf("%lf",&vet[i]);
		soma+=vet[i];	
	}
	
	sort(vet.begin(),vet.end());
	ind i = n-1;
	
	for(int i = 0;i<n-1 and m;i++;m--){
		if( (soma - vet[i])*(n) < (soma + 1)/(n-i-1)){
			changes[ind]++;
			if(ind == k) ind --;
			soma++;
		
		}else soma-=vet[i];
	
	
	
	
	}
	
	printf("%.10lf ",soma/final_size );
	
	
	

}
