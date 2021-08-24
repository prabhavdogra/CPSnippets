#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct pref2d {
    vector<vector<int>> sm;
    pref2d(vector<vector<int>> a) {
        int n = a.size();
        int m = a[0].size();
        sm = vector<vector<int>> (n, vector<int> (m, 0));
        sm[1][1] = a[1][1];
        for(int i = 2 ; i < m ; i++)
            sm[1][i] = sm[1][i - 1] + a[1][i];
        for(int i = 2 ; i < n ; i++)
            sm[i][1] = sm[i - 1][1] + a[i][1];
        for(int i = 2 ; i < n ; i++)
            for(int j = 2 ; j < m ; j++)
                sm[i][j] = sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1] + a[i][j];
    }
    int query(int x1, int y1, int x2, int y2) {
        return sm[x2][y2] - sm[x1 - 1][y2] - sm[x2][y1 - 1] + sm[x1 - 1][y1 - 1];
    }
};

// NOTE: INDEXING IS 1 BASED

// query(x1, y1, x2, y2);
// 1: (x1, y1)
// 2: (x2, y2)

// - - - - - -
// - 1 @ @ @ -
// - @ @ @ 2 -
// - - - - - -

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<vector<int>> a{{0, 0, 0, 0},
                          {0, 1, 2, 3},
                          {0, 3, 4, 5}};
    pref2d p(a);
    // p.query(x1, y1, x2, y2);
  
    return 0;
}
