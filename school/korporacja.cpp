#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 15;

bool vis[N];
vector <int> G[N];
int pre[N], post[N];

int n;
int num;

void DFS(int x) {
    vis[x] = 1;
    pre[x] = ++num;
    for(int y : G[x]) {
        if(vis[y])
            continue;
        DFS(y);
    }
    post[x] = num;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a;
        scanf("%d", &a);
        G[a].push_back(i);
        G[i].push_back(a);
    }

    DFS(0);

    // for(int i = 0; i < n; i++) {
    //     printf("%d: %d - %d\n", i, pre[i], post[i]);
    // }

    while(true) {
        int a, b;
        scanf("%d", &a);
        if(a == -1)
            return 0;
        scanf("%d", &b);
        if(pre[a] < pre[b] and post[b] <= post[a]) 
            printf("TAK\n");
        else
            printf("NIE\n");
    }


    return 0;
}