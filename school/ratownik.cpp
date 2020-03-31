#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct P {
    int X, Y;

    void read() {
        scanf("%d %d", &X, &Y);
        return;
    }
    
    P operator-(P a) {
        return P{X - a.X, Y - a.Y};
    }

};


int n, k;
P r;

LL sq(int x) {
    return (LL)x * (LL)x;
}

bool inRange(P p1, P p2) {
    return sq(k) >= sq((p1 - p2).X) + sq((p1 - p2).Y);
}

int main() {
    scanf("%d %d", &n, &k);
    r.read();

    int cnt = 0;

    while(n-- > 0) {
        P d;
        d.read();
        if(!inRange(r, d)) cnt++;
    }

    printf("%d", cnt);
}