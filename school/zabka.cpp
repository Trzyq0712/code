#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e3 + 15;

int n, st, k;

pair <int, int> nodes[N];

bool vis[N];

LL sq(LL a) {
    return a * a;
}

LL distBetween(int a, int b) {
    int x1 = nodes[a].first, y1 = nodes[a].second;
    int x2 = nodes[b].first, y2 = nodes[b].second;
    return sq((LL)abs(x1 - x2)) + sq((LL)abs(y1 - y2));
}

void DFS(int x) {
    vis[x] = 1;
    for(int i = 1; i <= n; i++) {
        if(sq((LL)k) < distBetween(x, i) or vis[i])
            continue;
        DFS(i);
    }
}

int main() {
    scanf("%d %d %d", &n, &st, &k);
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        nodes[i] = {x, y};
    }

    DFS(st);

    // for(int i = 1; i <= n; i++) printf("%d %s", i, vis[i] ? "TAK\n" : "NIE\n");

    double distMax = 0;
    for(int i = 1; i <= n; i++) {
        // if(distBetween(st, i) > distMax)
        if(!vis[i]) continue;
        distMax = max(distMax, sqrt(distBetween(st, i)));
    }
    printf("%.3f", distMax + (double)k);
    return 0;
}