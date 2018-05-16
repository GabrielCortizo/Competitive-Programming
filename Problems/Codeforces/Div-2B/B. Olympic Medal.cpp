#include<bits/stdc++.h>
#define rep(i,b,c) for(int i=(int)b;i<(int)c;i++)
using namespace std;

int a[10000],b[10000],c[10000];

int main(){
	double A,B;
	double r1 =0,p1=0,p2=1e+9;
	double v;
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> v;
		r1 = max(v,r1);
	}
	cin >> n;
	rep(i,0,n){cin >> v; p1=max(p1,v);}
	cin >> n;
	rep(i,0,n){cin >> v; p2 =min(p2,v);}
	
	cin >> A >> B;
	v = r1*sqrt(1/( A/B*p2/p1 + 1));
	printf("%.10lf",v); 
	
}
