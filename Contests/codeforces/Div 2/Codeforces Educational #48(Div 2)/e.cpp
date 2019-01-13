#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;
	int max_a=0,max_b = 0;
	char c;
	scanf("%d ",&n);
	while(n--){
		scanf("%c %d %d ",&c,&a,&b);
		if(a<b) swap(a,b);
		if(c=='+'){
			max_a = max(max_a,a);
			max_b = max(max_b,b);
		}else{
		
			if(a>=max_a && b >= max_b)printf("YES\n");
			else printf("NO\n");
		}
	
	}
	

}
