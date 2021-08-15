#include <bits/stdc++.h>
using namespace std;
void d(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a[i].size(); j++)
            cout << a[i][j] << " \n"[j == a[i].size() - 1];
}

void rotate0(vector<vector<int>> &vec_) {
    int n = vec_.size();
    int m = vec_[0].size();
    vector<vector<int>> ans_vec(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans_vec[i][j] = vec_[n - j - 1][i];
        }
    }
    vec_ = ans_vec;
}


void rotate1(vector<vector<int>> &vec_) {
    int n = vec_.size() - 1;
    int m = vec_[0].size() - 1;
    vector<vector<int>> ans_vec(m + 1, vector<int>(n + 1));
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            ans_vec[j][n + 1 - i] = vec_[i][j];
        }
    }
    vec_ = ans_vec;
}


void rotation0Based() {
    vector<vector<int>> x{{1, 2, 3}, 
                          {4, 5, 6}};
    cout << "1 Rotation:\n";
    rotate0(x);
    d(x);
    auto rotate0 = [&] (vector<vector<int>> &vec_) {
        int n = vec_.size();
        int m = vec_[0].size();
        vector<vector<int>> ans_vec(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans_vec[i][j] = vec_[n - j - 1][i];
            }
        }
        vec_ = ans_vec;
    };
    cout << "2 Rotation:\n";
    rotate0(x);
    d(x);
}

void rotation1Based() {
    vector<vector<int>> x{{0, 0, 0, 0}, 
                          {0, 1, 2, 3}, 
                          {0, 4, 5, 6}};
    cout << "1 Rotation:\n";
    rotate1(x);
    d(x);
    auto rotate1 = [&] (vector<vector<int>> &vec_) {
        int n = vec_.size() - 1;
        int m = vec_[0].size() - 1;
        vector<vector<int>> ans_vec(m + 1, vector<int>(n + 1));
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                ans_vec[j][n + 1 - i] = vec_[i][j];
            }
        }
        vec_ = ans_vec;
    };
    cout << "2 Rotation:\n";
    rotate1(x);
    d(x);
}

signed main() {
    rotation0Based();
    rotation1Based();
    return 0;
}