#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int main(){
	double n, r, R,a;
	cin >> n >> r;
	double alpha = ((2.0*pi)/n)/2.0;
	a = sin(alpha)*2;
	R = (r*a)/(2.0-a);
	printf("%.8lf",R);
	

}
