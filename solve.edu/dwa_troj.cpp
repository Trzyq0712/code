#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int n;

struct P {
    int X, Y;

    void read() {
        scanf("%d %d", &X, &Y);
        return;
    }
    
    P operator-(P a) {
        return P{X - a.X, Y - a.Y};
    }

    int operator*(P a) {
        return X * a.Y - Y * a.X;
    }
};

int scalar(P p1, P p2, P k) {
    p2 = p2 - p1;
    k = k - p1;
    return p2 * k ;
}


vector <P> t1, t2;

bool isInside(vector <P> &k1, vector <P> &k2) {
    pair <int, int> d[] = {{0, 1}, {1, 2}, {2, 0}};
    vector <int> side;
    for(int i = 0; i < 3; i++) {
        
        int more = 0, less = 0, eq = 0;
        for(auto k : k2) {
            int s = scalar(k1[d[i].first], k1[d[i].second], k);
            if(s > 0) 
                more++;
            else if(s < 0)
                less ++;
            else
                eq++;
        }
        if(more + eq == 3)
            side.push_back(1);
        else if(less + eq == 3)
            side.push_back(2);
        else
            side.push_back(-1);

    }
    if(side[0] == side[1] and side[1] == side[2] and side[0] != -1)
        return true;
    else
        return false;
    
}

int main() {
    for(int i = 0; i < 3; i++) {
        P p;
        p.read();
        t1.push_back(p);
    }
    for(int i = 0; i < 3; i++) {
        P p;
        p.read();
        t2.push_back(p);
    }
    printf("%s", (isInside(t1, t2) or isInside(t2, t1)) ? "TAK" : "NIE");

    return 0;
}