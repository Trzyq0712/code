// Jakub Trzykowski 
// OI27 etap II, dzień 0
// zadanie: Wakacje Bajtazara
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e6 + 15;

int n;

struct node {
    LL val; // atrakcyjność miasta
    int parent;
    vector <int> child;
    LL V; // zwiedzanie miasta
    LL W; // pisanie w mieście
};

node tre[N];

vector <int> G[N];
LL val[N];

void DFS(int x, int parent) {
    tre[x].parent = parent;
    int bestChild;
    LL sumOfChildren = 0;
    for(int y : G[x]) {
        if(y == parent)
            continue;
        tre[x].child.push_back(y);
        DFS(y, x);
        sumOfChildren += tre[y].val;
        tre[x].V = max(tre[y].W, tre[x].V);
        
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &tre[i].val);
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
    }

    if(n == 1) {
        printf("%lld \n1 \n1", tre[1].val);
        return 0;
    }
    else if(n == 2) {
        int city = (tre[1].val > tre[2].val) ? 1 : 2;
        printf("%lld \n1 \n%d", tre[city].val, city);
        return 0;
    }


    return 0;
}