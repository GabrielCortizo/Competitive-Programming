#include<bits/stdc++.h>
using namespace std;
int a[1009];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) cin >> a[i];
	int ans=0,minimo = 10000000;
	
	for(int i = 1;i<=100;i++){
		int soma = 0;
		for(int j = 0;j<n;j++){
			if(a[j] > i){
				soma += a[j]-i-1;
			}else if(a[j] < i){
				soma += i-a[j]-1;
			}
			
		}
		//cout<<soma<<endl;
		if(soma < minimo){
			minimo = soma;
			ans = i;
		}
	}
	
	cout<<ans <<" "<<minimo;

}
