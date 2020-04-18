#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 15;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool m[N][N];

void draw() {
    for(int i = 1; i <= 50; i++) {
        for(int j = 1; j <= 50; j++) {
            if(m[i][j]) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int x = 25, y = 25;
    int d = 3;
    m[x][y] = 1;
    for(int jump = 2; jump < 52; jump += 2) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < jump; j++) {
                x += dx[d];
                y += dy[d];
                m[x][y] = 1;
                cout << x << " " << y << "\n";
                if(x == 50 and y == 50){
                    draw();
                    return 0;
                }
            }
            d++;
            d %= 4;
        }
    }
}
