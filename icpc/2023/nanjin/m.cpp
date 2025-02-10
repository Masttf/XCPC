#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
struct node{
    int mx, sum, val, tag;
    int mxpos, mipos;
};
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> pre(n + 1), suf(n + 1);
    pre[1] = a[1], suf[n] = a[n];
    for(int i = 2; i <= n; i++)pre[i] = max(pre[i - 1], a[i]);
    for(int i = n - 1; i >= 1; i--)suf[i] = max(suf[i + 1], a[i]);
    vector<node>tr(n * 4);
    auto up = [&](node x, node y) -> node{
        node res = {0, 0, 0, 0, 0};
        res.mx = max(x.mx, y.mx);
        if(x.mx == res.mx){
            res.mxpos = x.mxpos;
            res.mipos = x.mipos;
        }
        if(y.mx == res.mx){
            res.mxpos = y.mxpos;
            res.mipos = y.mipos;
        }
        if(x.mx == y.mx){
            res.mxpos = y.mxpos;
            res.mipos = x.mipos;
        }
        res.sum = x.sum + y.sum;
        res.val = x.val + y.val;
        return res;
    };
    auto cg = [&](node &x, int val, int len) -> void{
        x.val = val * len;
        x.tag = val;
    };
    auto down = [&](int p, int l, int r) -> void{
        if(tr[p].tag){
            int mid = (l + r) >> 1;
            cg(tr[p << 1], tr[p].tag, mid - l + 1);
            cg(tr[p << 1 | 1], tr[p].tag, r - mid);
            tr[p].tag = 0;
        }
    };
    auto bulid = [&](auto self, int l, int r, int p) -> void{
        if(l == r){
            tr[p].mx = a[l];
            tr[p].sum = a[l];
            tr[p].val = min(pre[l], suf[l]);
            tr[p].mxpos = tr[p].mipos = l;
            return ;
        }
        int mid = (l + r) >> 1;
        self(self, l, mid, p << 1);
        self(self, mid + 1, r, p << 1 | 1);
        tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
    };

    auto updata = [&](auto self, int l, int r, int x, int val, int p) -> void{
        if(l == r){
            tr[p].mx = a[l];
            tr[p].sum = a[l];
            tr[p].val = val;
            tr[p].mxpos = tr[p].mipos = l;
            return ;
        }
        down(p, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid)self(self, l, mid, x, val, p << 1);
        else self(self, mid + 1, r, x, val, p << 1 | 1);
        tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
    };
    auto updata_val = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
        if(x <= l && r <= y){
            cg(tr[p], val, r - l + 1);
            return ;
        }
        down(p, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid)self(self, l, mid, x, y, val, p << 1);
        if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
        tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
    };
    auto get_sum = [&](auto self, int l, int r, int x, int y, int p) -> int{
        if(x <= l && r <= y)return tr[p].sum;
        int res = 0;
        down(p, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid)res += self(self, l, mid, x, y, p << 1);
        if(y > mid)res += self(self, mid + 1, r, x, y, p << 1 | 1);
        return res;
    };
    auto query_l = [&](auto self, int l, int r, int x, int y, int val, int p) -> int{
        if(x <= l && r <= y){
            if(tr[p].mx < val)return -1;
            if(l == r)return l;
        }
        down(p, l, r);
        int mid = (l + r) >> 1;
        if(y > mid){
            int res = self(self, mid + 1, r, x, y, val, p << 1 | 1);
            if(res != -1)return res;
        }
        if(x <= mid)return self(self, l, mid, x, y, val, p << 1);
        return -1;
    };
    auto query_r = [&](auto self, int l, int r, int x, int y, int val, int p) -> int{
        if(x <= l && r <= y){
            if(tr[p].mx < val)return -1;
            if(l == r)return l;
        }
        down(p, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid){
            int res = self(self, l, mid, x, y, val, p << 1);
            if(res != -1)return res;
        }
        if(y > mid)return self(self, mid + 1, r, x, y, val, p << 1 | 1);
        return -1;
    };
    auto query = [&](auto self, int l, int r, int x, int y, int p) -> node{
        if(x <= l && r <= y)return tr[p];
        down(p, l, r);
        int mid = (l + r) >> 1;
        node res = {0, 0, 0, 0, 0};
        if(x <= mid) res = up(res, self(self, l, mid, x, y, p << 1));
        if(y > mid)res = up(res, self(self, mid + 1, r, x, y, p << 1 | 1));
        return res;
    };
    int q; cin >> q;
    bulid(bulid, 1, n, 1);
    for(int i = 1; i <=q; i++){
        // for(int k = 1; k <= n; k++){
        //     cout << a[k] << " \n"[k == n];
        // }
        int x, v; cin >> x >> v;
        a[x] += v;
        int l = -1, r = -1;
        if(x != 1)l = query_l(query_l, 1, n, 1, x - 1, a[x], 1);
        if(x != n)r = query_r(query_r, 1, n, x + 1, n, a[x], 1);
        int lmx = a[x], rmx = a[x];
        node t = query(query, 1, n, x, x, 1);
        if(t.val >= a[x]){
            updata(updata, 1, n, x, t.val, 1);
        }else{
            if(l != -1){
                lmx = a[l];
                if(l + 1 <= x - 1)updata_val(updata_val, 1, n, l + 1, x - 1, a[x], 1);
            }else{
                if(x > 1){
                    node res = query(query, 1, n, 1, x - 1, 1);
                    updata_val(updata_val, 1, n, res.mxpos, x - 1, res.mx, 1);
                }
            }
            if(r != -1){
                rmx = a[r];
                if(x + 1 <= r - 1)updata_val(updata_val, 1, n, x + 1, r - 1, a[x], 1);
            }else{
                if(x < n){
                    node res = query(query, 1, n, x + 1, n, 1);
                    updata_val(updata_val, 1, n, x + 1, res.mipos, res.mx, 1);
                }
            }
            updata(updata, 1, n, x, min(lmx, rmx), 1);
        }
        
        int res = tr[1].val - tr[1].sum;
        cout << res << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}