#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


struct P {
    LL X, Y;
    void read() {
        scanf("%lld %lld", &X, &Y);
    }

    P operator -(P b) {
        return P{X - b.X, Y - b.Y};
    }

    LL operator *(P b) {
        return X * b.Y - b.X * Y;
    }
};

int n;

bool doCross(P a1, P a2, P b1, P b2) {
    LL s1 = (a2 - a1) * (b1 - a1);
    LL s2 = (a2 - a1) * (b2 - a1);
    LL s3 = (b2 - b1) * (a1 - b1);
    LL s4 = (b2 - b1)  * (a2 - b1);
    // printf("s1: %lld\ns2: %lld\ns3: %lld\ns4: %lld\n", s1, s2, s3, s4);
    if((((s1 > 0) xor (s2 > 0)) or s1 == 0 or s2 == 0) and (((s3 > 0) xor (s4 > 0)) or s3 == 0 or s4 == 0))
        return true;
    return false;
}

int main() {
    scanf("%d", &n);
    while(n-- > 0) {
        P a1, a2, b1, b2;
        a1.read();
        a2.read();
        b1.read();
        b2.read();
        printf("%s", (doCross(a1, a2, b1, b2) ? "TAK\n" : "NIE\n"));
    }
    // printf("%d", 0^1);

    return 0;
}