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
    LL sumOfChildren;
    LL V; // zwiedzanie miasta
    LL W; // pisanie w mieście
    int topV;
    int topW;
    int secBestV;
    int secBestW;
};

node tre[N];

vector <int> G[N];
LL val[N];

void DFS(int x, int parent) {
    tre[x].parent = parent;
    for(int y : G[x]) {
        if(y == parent)
            continue;
        tre[x].child.push_back(y);
        DFS(y, x);
        tre[x].sumOfChildren += tre[y].val;

        if(tre[y].V - tre[y].val >= tre[x].W) { // piszemy w tym mieście
            tre[x].W = tre[y].V - tre[y].val;
            tre[x].secBestW = tre[x].topW;
            tre[x].topW = y;
        }

        if(tre[y].W >= tre[x].V) { // odwiedzamy to miasto
            tre[x].V = tre[y].W;
            tre[x].secBestV = tre[x].topV;
            tre[x].topV = y;
        }


    }

    tre[x].W += tre[x].sumOfChildren;

    tre[x].V += tre[x].val;

}

// void getPath

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &tre[i].val);
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }


    DFS(1, 0);

    // for(int i = 1; i <= n; i++) {
    //     printf("%d: V: %lld topV: %d W: %lld topW: %d \n", i, tre[i].V, tre[i].topV, tre[i].W, tre[i].topW);
    // }

    LL maxRes = 0;
    bool visitingStart;

    for(int i = 1; i <= n; i++) {
        auto p = tre[i];
        LL resVisinting = tre[p.topW].W + tre[p.secBestW].W + p.val;
        LL resWriting = 
            p.sumOfChildren - tre[p.topV].val + tre[p.topV].V - tre[p.secBestV].val + tre[p.secBestV].V + tre[p.parent].val;
        if(tre[i].child.size() >= 2) {
            

        }
    }




    return 0;
}