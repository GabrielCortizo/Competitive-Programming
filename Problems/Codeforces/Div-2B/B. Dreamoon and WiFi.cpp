#include<bits/stdc++.h>
#define x first
#define y second
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
using namespace std;
typedef pair<int,int> ii;

int main(){
	ii a{0,0},b{0,0};
	string sa,sb;
	double cont = 0;
	cin >> sa >> sb;
	rep(i,0,sa.size()){
		if(sa[i] == '+') a.x++;
		else a.y++;
	}
	rep(i,0,sb.size()){
		if(sb[i] == '+')b.x++;
		else if(sb[i] == '-') b.y++;
	}
	int size = sb.size() - b.x - b.y;
	
	for(int i = 0;i<(1<<size);i++){
		int x=0,y=0;
		rep(j,0,size){
			if(i & 1<<j)x++;
			else y++;
		}
		//cout << x << " "<<y<<endl;
		if(b.y + y  == a.y && b.x + x == a.x)cont++;
	}
	double s = (double)size;
	printf("%.12lf",cont/pow(2,size));
	
	
}
