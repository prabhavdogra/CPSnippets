#include <bits/stdc++.h>
using namespace std;

struct query {
    int l, r, id;
};

struct queryResult { 
    int cnt = 0; 
};

struct mos {
    static void add(vector<int> &a, int id, queryResult &res);
    static void remove(vector<int> &a, int id, queryResult &res);
    static vector<queryResult> cal(vector<int> &a, vector<query> &q) {
        int l = 0, r = -1, n = a.size(), blk_sz = sqrt(n);
        queryResult res;
        vector<queryResult> ans(q.size());
        sort(q.begin(), q.end(), [&] (const query &p1, const query &p2) {
            if(p1.l/blk_sz == p2.l/blk_sz) 
                return ((p1.l/blk_sz) & 1) ? (p1.r > p2.r) : (p1.r < p2.r);
            return (p1.l/blk_sz < p2.l/blk_sz);
        });
        for(int i = 0; i < q.size(); i++) {
            int ql = q[i].l;
            int qr = q[i].r;
            int id = q[i].id;
            // Extending range
            while (l > ql) add(a, --l, res);
            while (r < qr) add(a, ++r, res);
            // Reducing range
            while (l < ql) remove(a, l++, res);
            while (r > qr) remove(a, r--, res);
            ans[id] = res;
        }
        return ans;
    }
};

void mos::add(vector<int> &a, int id, queryResult &res) {
    
}
void mos::remove(vector<int> &a, int id, queryResult &res) {
    
}
// mos::cal(a, q);

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    return 0;
}
