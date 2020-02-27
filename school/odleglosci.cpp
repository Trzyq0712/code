#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 15;

bool vis[N];
int dist[N];

vector <int> G[N];

int n, m;

void BFS(int x) {
    queue <int> q;
    vis[x] = 1;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(int y : G[x]) {
            if(vis[y]) continue;
            vis[y] = 1;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
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
    BFS(1);
    for(int i = 1; i <= n; i++) {
        printf("%d\n", (vis[i] ? dist[i] : -1));
    }
}