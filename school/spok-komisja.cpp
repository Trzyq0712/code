#include <bits/stdc++.h>
#define pu push_back
using namespace std;

const int N = 8e3 + 15;

int n, m;

vector <int> G[2 * N], T[2 * N];
unordered_set <int> mem[2 * N];
int group[2 * N];
int vis[2 * N];
int id;
unordered_set <int> G_SCC[2 * N];

stack <int> s;

void DFS_ord(int x) {
    vis[x] = 1;
    for(int y : G[x]) {
        if(vis[y]) continue;
        DFS_ord(y);
    }
    s.push(x);
}

void DFS_SCC(int x) {
    group[x] = id;
    mem[id].insert(x);
    vis[x] = 1;
    for(int y : T[x]) {
        if(vis[y]) continue;
        DFS_SCC(y);
    }
}

void SCC() {
    // Building Strongly Connected Compounds
    for(int i = 1; i <= 2 * n; i++) {
        if(vis[i]) continue;
        DFS_ord(i);
    }
    fill(vis, vis + 2 * N, 0);
    while(!s.empty()) {
        int x = s.top();
        s.pop();
        if(vis[x]) continue;
        id++;
        DFS_SCC(x);
    }

    // Building a graph from SCC
    for(int i = 1; i <= 2 * n; i++) {
        for(int j : G[i]) {
            int x = group[i],
                y = group[j];

            if(x == y) continue;
            G_SCC[y].insert(x);
        }
    }
}

int incoming[2 * N];
set <int> K;

void toposort() {
    queue <int> q;
    for(int i = 1; i <= id; i++) {
        for(int j : G_SCC[i]) {
            incoming[j]++;
        }
    }
    for(int i = 1; i <= id; i++) {
        if(incoming[i] == 0) q.push(i);
    }
    
    fill(vis, vis + 2 * N, 0);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int a : mem[x]) {
            int b = a + ((a % 2) ? 1 : -1);
            vis[group[b]] = 1;
            K.insert(a);
        }
        for(int y : G_SCC[x]) {
            if(--incoming[y] == 0) {
                q.push(y);
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int a2 = a + ((a % 2) ? 1 : -1);
        int b2 = b + ((b % 2) ? 1 : -1);
        // cout << "a: " << a << " " << a2 << "\n";
        G[a].pu(b2);
        G[b].pu(a2);
        T[b2].pu(a);
        T[a2].pu(b);
    }

    // for(int i = 1; i <= 2 * n; i++) {
    //     cout << i << ": ";
    //     for(int j : G[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << "\n";
    // }


    SCC();

    // Check if 2 members of a party in the same compound
    // cout << "members:\n";
    // for(int i = 1; i <= id; i++) {
    //     cout << i << ": ";
    //     for(int x : mem[i]) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << "SCC gaph:\n";
    // for(int i = 1; i <= id; i++) {
    //     cout << i << ": ";
    //     for(int j : G_SCC[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << "\n";
    // }
 
    for(int i = 1; i <= id; i++) {
        for(int x : mem[i]) {
            int y = x + ((x % 2) ? 1 : -1);
            if(mem[i].count(y)) {
                cout << "NIE";
                return 0;
            }
        }
    }
    
    toposort();

    if(K.size() != n) {
        cout << "NIE";
        return 0;
    }

    for(int i : K) {
        cout << i << '\n';
    }


    return 0;
}

