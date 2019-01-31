#include<bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
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
	cout.precision(12);
	int n;
	double x,y;
	pt ponto;
	vector<pt> vet;
	string str;
	while(getline(cin, str)){
		stringstream ss(str);
		vet.clear();
		
		while(ss >> x >> y){
			ponto = {x,y};
			vet.push_back(ponto);
		}
		double n = vet.size(),s = 0;
	 
		convex_hull(vet);
		vet.push_back(vet.front());
		
		for(int i = 0;i<vet.size()-1;i++){
			s+= hypot(vet[i].x-vet[i+1].x, vet[i].y-vet[i+1].y);
		}		
		
		//cout<<s<<endl;
		s = 100*n/(1.0+s);
		
		cout<<s<<"\n";
	}

}