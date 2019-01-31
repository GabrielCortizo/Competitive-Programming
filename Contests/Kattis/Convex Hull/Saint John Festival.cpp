#include<bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
    bool operator < (const pt &b){
    	return this->x < b.x || (this->x == b.x && this->y < b.y);
    }
    bool operator > (const pt &b){
    	return this->x > b.x || (this->x == b.x && this->y > b.y);
    }
    bool operator >= (const pt &b){
    	return this->x > b.x || (this->x == b.x && this->y >= b.y);
    }
    bool operator <= (const pt &b){
    	return this->x < b.x || (this->x == b.x && this->y <= b.y);
    }
};

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
vector<pt> up,down,L,l;
void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end());
    pt p1 = a[0], p2 = a.back();
    //vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main(){
	int nl,nL;
	double x,y;
	cin >> nl;
	for(int i = 0;i<nl;i++){
		cin >>x >> y;
		L.push_back({x,y});
	
	}
	convex_hull(L);
	cin >> nL;
	for(int i = 0;i<nL;i++){
		cin >>x >>y;
		l.push_back({x,y});
	}

	vector<pt> sol;
	sort(l.begin(),l.end());
	//cout<<l.size()<<endl;
	
	
	int ind = 0;
	
	while(ind < l.size() && l[ind] < up[0]) ind++;
//	
	for(int i = 0;i<up.size()-1;i++){
		
		while(ind < l.size() && l[ind] <= up[i+1] && up[i] <= l[ind]){
		
			if(!cw(up[i], l[ind], up[i+1])) sol.push_back(l[ind]);
			ind++;
		}
	}
	
	ind = 0;
	l = sol;
	sol.clear();
	up = down;
	
	while(ind < l.size() && l[ind] < up[0]) ind++;

	for(int i = 0;i<up.size()-1;i++){
		
		while(ind < l.size() && l[ind] <= up[i+1] && up[i] <= l[ind]){
		
			if(!ccw(up[i], l[ind], up[i+1])) sol.push_back(l[ind]);
			ind++;
		}
	}	
	
	cout<<sol.size()<<endl;
	
}
