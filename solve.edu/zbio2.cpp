#include <bits/stdc++.h>
using namespace std;

vector<int> a;

map<int, int, greater<int>> m;

int n;

void map_erase(int val){
    m[val]--;
    if(m[val] == 0) m.erase(val);
}

void map_add(int val){
    m[val]++;
    if(m[val] == 0) m.erase(val);
}

void merase(int i, int j){
    if(i > 0){
        map_erase(abs(a[i] - a[i - 1]));
    }
    if(i + 1 < n){
        map_erase(abs(a[i] - a[i + 1]));
    }
    if(j > 0){
        map_erase(abs(a[j] - a[j - 1]));
    }
    if(j + 1 < n){
        map_erase(abs(a[j] - a[j + 1]));
    }
}

void madd(int i, int j){
    if(i > 0){
        map_add(abs(a[i] - a[i - 1]));
    }
    if(i + 1 < n){
        map_add(abs(a[i] - a[i + 1]));
    }
    if(j > 0){
        map_add(abs(a[j] - a[j - 1]));
    }
    if(j + 1 < n){
        map_add(abs(a[j] - a[j + 1]));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maxxid = 0;
    for(int i = 0; i < n - 1; i++){
        m[abs(a[i + 1] - a[i])]++;
    }
    int res = m.begin()->first;
    for(int j = maxxid; j < min(n, maxxid + 2); j++){
        for(int i = 0; i < n; i++){
            if(i == j) continue;
            merase(i, j);
            swap(a[i], a[j]);
            madd(i, j);
            res = min(res, m.begin()->first);
            merase(i, j);
            swap(a[i], a[j]);
            madd(i, j);
        }
    }
    cout << res;

    return 0;
}