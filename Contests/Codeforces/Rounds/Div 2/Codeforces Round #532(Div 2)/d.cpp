#include<bits/stdc++.h>
using namespace std;
const int sz = 1009;
bool mapa[sz][sz];
int pos[sz][2];
int x,y;
void move(int x_, int y_){
	int a,b,c;
	if(mapa[x+x_][y+y_]) x_ = 0;
		x+=x_;
		y+=y_;
	cout<<x <<" "<<y<<endl;
	cin >> a >> b >>c;
	if(a == -1 || b== -1 || c == -1) exit(0);
	if(!a || !b || !c) exit(0);
	mapa[pos[a][0]][pos[a][1]] = 0;
	pos[a][0] = b;
	pos[a][1] = c;
	mapa[b][c] = 1;

}

int main(){
	int a,b,c;
	cin >> x >> y;
	for(int i = 1;i<=666;i++){
		cin >> a >> b;
		mapa[a][b] = 1;
		pos[i][0] = a;
		pos[i][1] = b; 
	}
	while(x<500) move(1,0);
	while(x>500) move(-1,0);
	while(y>500) move(0,-1);
	while(y<500) move(0,+1);
	int q1=0,q2=0,q3=0,q4=0,posi = 1;
	for(int i = 1;i<=999;i++){
		for(int j = 1;j<=999;j++){
			if(mapa[i][j]){
				if(i<500 && j<500)
					q3++;
				if(i<500 && j>500)
					q4++;
				if(i>500 && j<500)
					q1++;
				if(i>500 && j>500)
					q2++;
			}
		}
	}
	int mini = q1;
	if(q2 < mini){
		posi = 2;
		mini = q2;
	}
	if(q3 < mini){
		posi = 3;
		mini = q3;
	}
	if(q4 < mini){
		mini = q4;
		posi = 4;
	}
	if(posi == 1) while(1) move(-1,1);
	if(posi == 2) while(1) move(-1,-1);
	if(posi == 3) while(1) move(1,1);
	if(posi == 4) while(1) move(1,-1);
}	
