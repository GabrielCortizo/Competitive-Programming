#include<bits/stdc++.h>
using namespace std;
int cont[3],miss[3];
deque<int> pos[3];
int main(){
	int n;
	string str;
	cin >> n;
	cin >> str;
	for(int i = 0;i<n;i++){
		int c = str[i] - '0';
		pos[c].push_back(i);
	}
	for(int i = 0;i<3;i++)
		miss[i] = str.size()/3 - pos[i].size();
		
	if(miss[2]<0){
	
		while(miss[2]<0 && miss[0]>0){
			miss[2]++;
			miss[0]--;
			pos[0].push_back(pos[2].front());
			pos[2].pop_front();
		
		}
		while(miss[2]<0 && miss[1]>0){
			miss[2]++;
			miss[1]--;
			pos[1].push_back(pos[2].front());
			pos[2].pop_front();
		
		}
	}
//	cout<<"oi"<<endl;
	if(miss[0]<0){
	
		while(miss[0]<0 && miss[2]>0){
			miss[0]++;
			miss[2]--;
			pos[2].push_back(pos[0].back());
			pos[0].pop_back();
		
			
		}
		//cout<<"e"<<endl;
		while(miss[0]<0 && miss[1]>0){
			miss[0]++;
			miss[1]--;
			pos[1].push_back(pos[0].back());
			pos[0].pop_back();
		
		}
	}
	//	cout<<"d"<<endl;
	 if(miss[1]<0){
	
		while(miss[1]<0 && miss[2]>0){
			miss[1]++;
			miss[2]--;
			pos[2].push_back(pos[1].back());
			pos[1].pop_back();
		
		}
		while(miss[1]<0 && miss[0]>0){
			miss[1]++;
			miss[0]--;
			pos[0].push_back(pos[1].front());
			pos[1].pop_front();
		}	
	}
	for(int i = 0;i<3;i++){
		char c = i + '0';
		for(auto p : pos[i]){
			str[p] = c;
		}
	}
	cout<<str;	
	
}
