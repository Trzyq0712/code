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

    LL operator*(P a) {
        return (LL)X * (LL)a.Y - (LL)Y * (LL)a.X;
    }
};

bool diffSign(const LL a, const LL b) {
    return ((a > 0 and b < 0) or (a < 0 and b > 0));
}

bool isBetween(const P a, const P b, const P x) {
    return (min(a.X, b.X) <= x.X and x.X <= max(a.X, b.X) and min(a.Y, b.Y) <= x.Y and x.Y <= max(a.Y, b.Y));
}   

bool doCross(P p1, P p2, P p3, P p4) {
    LL s1 = (p2 - p1) * (p3 - p1);
    LL s2 = (p2 - p1) * (p4 - p1);
    LL s3 = (p4 - p3) * (p1 - p3);
    LL s4 = (p4 - p3) * (p2 - p3);
    if(diffSign(s1, s2) and diffSign(s3, s4)) return true;
    else if((s1 == 0 and isBetween(p1, p2, p3)) or (s2 == 0 and isBetween(p1, p2, p4)) or (s3 == 0 and isBetween(p3, p4, p1)) or (s4 == 0 and isBetween(p3, p4, p2))) return true;
    return false;

}

int main() {
    scanf("%d", &n);
    while(n-- > 0) {
        P p1, p2, p3, p4;
        p1.read();
        p2.read();
        p3.read();
        p4.read();
        printf("%s\n", (doCross(p1, p2, p3, p4) ? "TAK" : "NIE"));
    }
    return 0;
}