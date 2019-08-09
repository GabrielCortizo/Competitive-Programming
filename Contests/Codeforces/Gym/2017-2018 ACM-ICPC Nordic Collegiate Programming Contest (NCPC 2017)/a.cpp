#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
typedef pair<int,int> ii;
const int ms = 5e5+9;
 
double l, a,b, t, r;
int n;
 
vector<double> vet;
 
double dp[ms], wt, wr;
 
double tempo(double v1, double v2){
 
    double d = v2 - v1;
    if(d <= wt)
        return d/a;
    if(d <= wt + wr)
        return t + (d-wt)/b;
    return (t + r + (d - wt - wr)/a);
 
 
}
 
double solve(int id){
	
    if(id == n-1)
        return tempo(vet[n-1], l);
        
    double &ans = dp[id];
    
    if( ans != 1e12) return ans;
    
    ans = tempo(vet[id], l);
    
    double d1 = tempo(vet[id], vet[id+1]);
    if(d1 <= wt)
        ans = min(ans, solve(id+1) + d1);
        
    auto it2 = lower_bound(vet.begin(),vet.end(),vet[id]+wr + wt);
    
    if(it2!=vet.end()){
        auto it1 = it2 - vet.begin();
        if(it1 > id and it1 < n){ 
        d1 = tempo(vet[id], vet[it1]);
        ans = min(ans, solve(it1) + d1);
        }
    }
    if(it2 != vet.begin()){
        it2--;
        auto it1 = it2 - vet.begin();
        if(it1 > id and it1<n){
            d1 = tempo(vet[id], vet[it1]);
            ans = min(ans, solve(it1) + d1);
            
        }
    }
    return ans;
}
vector<int> resp;
 
void rec(int id){
    if(id >= n-1) return ;
 
    
    double d1 = tempo(vet[id], vet[id+1]);
    if(d1 <= wt){
    		
        if(solve(id+1) + d1 == dp[id]){
            resp.push_back(id+1);
            rec(id+1);
            return ;
        }
    
    }
        
    auto it2 = lower_bound(vet.begin(),vet.end(),vet[id]+wr + wt);
    
    
    
    if(it2!=vet.end()){
        auto it1 = it2 - vet.begin();
        if(it1 > id and it1 < n){ 
            d1 = tempo(vet[id], vet[it1]);
            if(solve(it1) + d1 == dp[id]){
                resp.push_back(it1);
                rec(it1);
                return ;
            }
        }
    }
    if(it2 != vet.begin()){
        it2--;
        auto it1 = it2 - vet.begin();
        if(it1 > id and it1<n){
            d1 = tempo(vet[id], vet[it1]);
            
            if(solve(it1) + d1 == dp[id]){
                resp.push_back(it1);
                rec(it1);
                return ;
            }
        }
    }
 
}
 
 
main(){
		cout<<fixed<<setprecision(10);
    cin >> l >> a >> b >> t >> r >> n;
    double val;
    for(int i = 0;i<n;i++){
        cin >> val;
        vet.emplace_back(val);
    }
    wt = a*t;
    wr = b*r;
    if(n == 0){
        cout<<0;
        return 0;
    }
    for(int i = 0;i<ms;i++) dp[i] = 1e12;
    
    solve(0);
    
    resp.push_back(0);
    
    rec(0);
    sort(resp.begin(),resp.end());
//  cout<<resp.size()<<endl;
    resp.erase(unique(resp.begin(),resp.end()),  resp.end());
    cout<<resp.size()<<endl;
    for(auto it: resp) cout<<it<<" ";
}
