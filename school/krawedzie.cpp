#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 15;

int n, m, q;

bool edge[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    scanf("%d", &q);
    while(q-- > 0) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%s\n", (edge[a][b] ? "TAK" : "NIE"));
    }

    return 0;
}