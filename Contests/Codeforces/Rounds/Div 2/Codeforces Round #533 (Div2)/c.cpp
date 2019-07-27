#include<bits/stdc++.h>
using namespace std;
const int ms = 200009;
long long memo[ms][3],l,r;
int n;
long long m[3];
int main(){
  cin >> n >> l >> r;
  for(int i = 0;i<3;i++) {
  	double r1 = r-i,l1 = l-i;
  	double v1 = floor(r1/3.0);
  	double v2 = ceil(l1/3.0);
  //	cout<<v2 <<" "<<v1<<endl;
  	m[i] = v1 >= v2?(int)v1-v2+1:0;
  		
  }
  //for(int i = 0;i<3;i++) cout<<m[i]<<" ";
  memo[0][0] = 1;
  long long M=1e9+7;
  for(int i = 0;i<=n;i++){
    for(int j = 0;j<3;j++){
      for(int k = 0;k<3;k++){
      
        	memo[i+1][(j+k)%3] = ((memo[i+1][(j+k)%3])%M +  (memo[i][j]*m[k])%M)%M;
       
        
      }
    }
  }
 
  cout<<(memo[n][0]%M);
  
  
}
