#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 15;

vector <int> G[N];

bool vis[N];

int n, m;

void DFS(int x) {
    vis[x] = 1;
    for(int y : G[x]) {
        if(vis[y])
            continue;
        DFS(y);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    DFS(1);
    for(int i = 1; i <= n; i++) {
        printf("%s", (vis[i] ? "TAK\n" : "NIE\n"));
    }
}