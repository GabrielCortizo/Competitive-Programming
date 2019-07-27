#include<bits/stdc++.h>
using namespace std;
const int ms = 1e+6 + 9;
typedef long long ll;
typedef pair<ll,ll> lll;
lll st[ms<<2];
int x[ms], cost[ms], t[ms];
vector<int> g[ms],d[ms];

ll query(int p, int l, int r, ll T){
  //if(T<=0 || !st[p].first || !st[p].second) return 0;
  if(l == r) return min(T/l, st[p].second);
  int m = (l+r)/2;
  if(st[p<<1].first <= T) return st[p<<1].second + query(p<<1|1,m+1,r,T-st[p<<1].first);
  else return query(p<<1,l,m,T);
  
}

void upd(int p, int l, int r, int te, int qnt){
  st[p].first  += 1ll*te*qnt;
  st[p].second += qnt;
  if(l == r) return;
  int m = (l+r)/2;
  if(te > m) upd(2*p+1,m+1,r,te,qnt);
  else upd(2*p,l,m,te,qnt);
}

ll dfs(int v, ll T){
 
  upd(1,1,ms,cost[v],x[v]);
  ll temp=0,m1=0,m2=0, maxi = query(1,1,ms,T);
  for(int i = 0;i<g[v].size();i++){
    int no = g[v][i];
    ll w = 2ll*d[v][i];
    if(w > T) continue;
    temp = dfs(no,T-w);
    if(temp > m1){m2 = m1; m1 = temp;}
    else if(temp > m2) m2 = temp;
  }
  upd(1,1,ms,cost[v],-x[v]);
  if(v == 1) return max(maxi,m1);
  else return max(maxi,m2);
}

int main(){
  int n,a,b;
  ll T;
  cin  >> n >>T;
  for(int i = 1;i<=n;i++) cin >> x[i];
  for(int i = 1;i<=n;i++) cin >> cost[i];
  for(int i = 2;i<=n;i++){
    cin >> a >> t[i];
    g[a].push_back(i); 
    d[a].push_back(t[i]);
  }
  cout<<dfs(1,T);
  
}

