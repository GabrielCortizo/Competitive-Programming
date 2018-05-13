#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define clr(v,i) memset(v,i,sizeof(v))
#define rep(i,b,c) for(int i =(int)b;i<(int)c;i++)
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
int matrix[10][10];
int xs[] = {-2,-2,-1,+1,+2,+2,-1,+1};
int ys[] = {-1,1,2,2,-1,1,-2,-2};

bool isValid(int i, int j){
	return (i<8 && i>=0 && j>=0 && j<8);
}




int main(){
	char a[3],b[3];
	int x0,y0,x1,y1;
	ii u;
	
	while(cin >> a >> b){
		clr(matrix,-1);
		
		x0 = a[0]-'a'; x1 = b[0]-'a';
		y0 = a[1]-'1'; y1 = b[1]-'1';
		matrix[x0][y0] = 0;
		queue<ii> q;
		q.push(ii(x0,y0));
		
		while(!q.empty() && matrix[x1][y1]==-1){
		
			 u = q.front();q.pop();		
			 rep(i,0,8){
			 	int xt = u.x + xs[i];
			 	int yt = u.y + ys[i];
			 	if(isValid(xt,yt)&& matrix[xt][yt]==-1){
			 		q.push(ii(xt,yt));
			 		matrix[xt][yt] = matrix[u.x][u.y]+1;
			 	}
			 	
			 	}
			 
			 }
		printf("To get from %s to %s takes %d knight moves.\n",a,b,matrix[x1][y1]);
		
		}
	}

