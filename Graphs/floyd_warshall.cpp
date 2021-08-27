#include <bits/stdc++.h>
using namespace std;
constexpr int64_t INF = 1e17;

// O(V^3)
vector<vector<int>> floydWarshall(vector<vector<int>> &adj_mat) {
    auto res = adj_mat;
    for (int i = 0; i < adj_mat.size(); i++) // Self-Loop
        res[i][i] = 0;
    for (int k = 0; k < adj_mat.size(); k++)
        for (int i = 0; i < adj_mat.size(); i++)
            for (int j = 0; j < adj_mat.size(); j++)
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj_mat(n, vector<int>(n, INF));
    auto dis = floydWarshall(adj_mat);
    
    return 0;
}
