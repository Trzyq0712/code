#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 15;

int n, q, m;


vector <int> G[N];
LL val[N];
int jp[N][20], dep[N];
// int num;
LL dist[N];

void DFS(int x, int parent) {
    dist[x] += val[x];
    // pre[x] = ++num;
    jp[x][0] = parent;
    for (int j = 1; j < 20; j++) {
        jp[x][j] = jp[jp[x][j - 1]][j - 1];
    }
    
    for (int i = 0; i < (int)G[x].size(); i++) {
        int y = G[x][i];
        if(y == parent) continue;
        dep[y] = dep[x] + 1;
        dist[y] += dist[x];
        DFS(y, x);
    }
    // post[x] = num;
}

int LCA(int a, int b) {
    if (dep[a] > dep[b]) {
        swap(a, b);
    }
    for (int i = 19; i >= 0; i--) {
        if (dep[jp[b][i]] >= dep[a]) {
            b = jp[b][i];
        }
    }
    if(a == b) {
        // printf("elo\n");
        return a;
    }

    for (int i = 19; i >= 0; i--) {
        if (jp[a][i] != jp[b][i]) {
            a = jp[a][i];
            b = jp[b][i];
        }
    }
    return jp[a][0];
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &val[i]);
    }

    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dep[1] = 1;

    for(int i = 0; i < 20; i++) {
        jp[1][i] = 1;
    }
    

    DFS(1, 1);

    // for(int i = 1; i <= n; i++) {
    //     printf("%d: ", i);
    //     for(int j = 0; j < 20; j++) {
    //         printf("%d ", jp[i][j]);
    //     }
    //     printf("\n");
    // }

    while(q-- > 0) {
        scanf("%d", &m);
        int a, b;
        int c, d;
        scanf("%d %d", &a, &b);
        for(int i = 1; i < m; i++) {
            scanf("%d %d", &c, &d);
            int l1, l2, l3, l4;
            l1 = LCA(a, c);
            l2 = LCA(a, d);
            l3 = LCA(b, c);
            l4 = LCA(b, d);

            // printf("l1: %d l2: %d l3: %d l4: %d\n", l1, l2, l3, l4);

            a = ((dep[l1] > dep[l2]) ? l1 : l2);
            b = (dep[l3] > dep[l4] ? l3 : l4);

            c = ((dep[l1] > dep[l3]) ? l1 : l3);
            d = ((dep[l2] > dep[l4]) ? l2 : l4);

            int d1 = dep[a] + dep[b] - 2 * dep[LCA(a, b)];
            int d2 = dep[c] + dep[d] - 2 * dep[LCA(c, d)];

            if(d2 < d1) {
                a = c;
                b = d;
            }
            
            // printf("a: %d b: %d\n", a, b);
        }

        printf("%lld\n", dist[a] + dist[b] - 2 * dist[LCA(a, b)] + val[LCA(a, b)]);
    }

    return 0;
}