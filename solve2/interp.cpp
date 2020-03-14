#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1005;
int dp[N][N];
int backdp[N][N];
vector<pair<int, int>> from[N][N];
const int64_t mod = 1e9 + 7;
int64_t res = 1;
set<string> res2;
int n, m;

bool lessthan1000 = true;
// map<int,  > layers;

vector <pair <int, int> > layers[N];
vector <LL> cnt[N];

string A, B;


// void dfs(int layer, string curr){
//     if(layer > dp[n][m]){
//         cout << curr << "\n";
//     }
//     else for(auto c : layers[layer]){
//         dfs(layer + 1, curr + c);
//     }
// }

set <string> ress;

int lastLayer = 0;

void DFS(int layer, int x, int y, string curr) {
    // cout << layer << ": " << x << ' ' << y << '\n';
    if(curr.size() == lastLayer) {
            ress.insert(curr);
            return;
    }
    for(int i = 0; i < layers[layer + 1].size(); i++) {
        if(layers[layer + 1][i].first > x and layers[layer + 1][i].second > y) {
            DFS(layer + 1, layers[layer + 1][i].first, layers[layer + 1][i].second, curr + A[layers[layer + 1][i].first - 1]);
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    
    cin >> n >> m;
    cin >> A >> B;

    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i] == B[j]){
                dp[i + 1][j + 1] = 1 + dp[i][j];
                // from[i + 1][j + 1].push_back({i, j});
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                // if(dp[i + 1][j] >= dp[i][j + 1]){
                //     dp[i + 1][j + 1] = dp[i + 1][j];
                //     // from[i + 1][j + 1].push_back({i + 1, j});
                // }
                // if(dp[i][j + 1] >= dp[i + 1][j]){
                //     dp[i + 1][j + 1] = dp[i][j + 1];
                //     // from[i + 1][j + 1].push_back({i, j + 1});
                // }
            }
            if(dp[i + 1][j + 1] > max(dp[i][j + 1], dp[i + 1][j])) {
                layers[dp[i + 1][j + 1]].push_back({i + 1, j + 1});
                cnt[dp[i + 1][j + 1]].push_back(0ll);
                lastLayer = dp[i + 1][j + 1];
            }
        }
    }

    for(auto &x : cnt[1]) {
        x = 1ll;
    }

    for(int i = 1; i < lastLayer; i++) {
        for(int j = 0; j < layers[i].size(); j++) {
            for(int k = 0; k < layers[i + 1].size(); k++) {
                if(layers[i + 1][k].first > layers[i][j].first and layers[i + 1][k].second > layers[i][j].second) {
                    cnt[i + 1][k] += cnt[i][j];
                    cnt[i + 1][k] %= mod;
                    
                }

            }
        }
    }

    LL resu = 0;

    for(LL i : cnt[lastLayer]) {
        resu += i;
        resu %= mod;
    }



    for(auto i : layers[1]) {
        string h;
        h += A[i.first - 1];
        DFS(1, i.first, i.second, h);
    }

    // for(auto x : layers){
    //     res *= x.second.size();
    //     if(res > 1000) lessthan1000 = false;
    //     res %= mod;
    // }
    // cout << n + m - 2 * dp[n][m] << " " << res << "\n";
    // if(lessthan1000){
    //     dfs(1, "");
    // }

    cout << n + m - 2 * lastLayer << " " << resu << "\n";

    for(auto word : ress) {
        cout << word << '\n';
    }


    return 0;
}