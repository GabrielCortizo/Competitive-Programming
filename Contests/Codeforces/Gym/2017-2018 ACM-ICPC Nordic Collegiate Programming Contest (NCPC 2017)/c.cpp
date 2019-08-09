#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
 
const int ms =1e5+9;
 
map<int,int> id_i;
set<ii> s[3], sol;
int n;
int v[ms][5];
 
vector<int> sides;
void insere(int i){
    int soma =0;
    
    for(int j = 0;j<3;j++){
        
        auto it = s[j].find({v[i][j], i});
        
        auto it1 = (it == s[j].begin())?s[j].end():it;
        it1--;
        it++;
        auto it2 = (it == s[j].end()) ? s[j].begin() : it;
        it--;
        
    //    cout<<it->first<<" "<<it1->first<<" "<<it2->first<<endl;
        
        if(it1->first == it->first or it->first == it2->first)  continue; 
        
        if(it1->first == it2->first){
            soma += 360;
            continue;
        
        }
    
        soma += ((*it2).first - (*it1).first + 360)%360;
   //     cout<<soma<<endl;
    }   
    v[i][4] = soma;
    sol.insert({soma, -v[i][3]});
 
}
 
void getSides(int ind){
    
    int id = id_i[ind];
    sol.erase(sol.begin());
    sides.clear();
    
    if(sol.size() <= 1)
        return;
    
    for(int i = 0;i<3;i++){
        
        auto it = s[i].find({v[id][i], id});
        
        auto it1 = (it == s[i].begin())?s[i].end():it;
        it1--;
        it++;
        auto it2 = (it == s[i].end()) ?s[i].begin():it;
        it--;
 
        sides.push_back(it1->second);
        sides.push_back(it2->second);
        
        s[i].erase(it);
    
    }
    sort(sides.begin(),sides.end());
    sides.erase(unique(sides.begin(),sides.end()), sides.end());
    
    for(auto &it: sides){
        
        sol.erase({v[it][4],-v[it][3]});
        v[it][4] = -1;  
    }
    
    for(auto &it: sides)
        insere(it); 
}
 
 
int main(){
    cin >> n;
    for(int i= 0;i<n;i++){
        for(int j = 0;j<4;j++)
            scanf("%d ",&v[i][j]);
            
        v[i][4] = -1;
        int id = v[i][3];
        
        for(int j =0;j<3;j++)   
            s[j].insert({v[i][j], i});
        id_i[id] = i;
    }
    
    for(int i = 0;i<n;i++) insere(i);
  
    while(sol.size()){
        //cout<<"oioi"<<endl;
        auto idx = - (sol.begin())->second;
        cout<<idx<<"\n";
        getSides(idx);
    
    }
    
}
