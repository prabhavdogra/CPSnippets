#include <bits/stdc++.h>
using namespace std;

// int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
// int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> vis, a;
 
bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) // Change condition
        return false;
    return true;
}

void dfs(int x, int y) {
    if(isValid(x, y)) {
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
    return;
}

void solve() {
    cin >> n >> m;
    vis.resize(n);
    a.resize(n);
    for(int i = 0; i < n; i++)
        vis[i].assign(m, 0), a[i].resize(m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0, 0);
}

int main() {   
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}