#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 15;

int n, m;

vector <int> G[N];
int incoming[N];


void toposort() {
    for(int i = 1; i <= n; i++) {
        for(int j : G[i]) {
            incoming[j]++;
        }
    }

    queue <int> q;
    vector <int> order;

    for(int i = 1; i <= n; i++) {
        if(incoming[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        if(q.size() > 1) {
            printf("NIE");
            return;
        }
        int x = q.front();
        q.pop();
        order.push_back(x);
        for(int y : G[x]) {
            if(--incoming[y] == 0)
                q.push(y);
        }
    }

    if((int)order.size() < n) {
        printf("NIE");
    }
    else {
        printf("TAK\n");
        for(int i : order) {
            printf("%d ", i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
    }

    toposort();

    return 0;
}