#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
template<class Info, class Tag>
struct LazySegmentTree{
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()){
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_){ //注意下标从1开始也就是[0] 是空
        init(init_);
    }
    void init(int n_, Info v_ = Info()){
        init(vector(n_ + 1, v_));
    }
    template<class T>
    void init(vector<T> init_){
        n = init_.size() - 1;
        info.assign(n * 4, Info());
        tag.assign(n * 4, Tag());
        auto bulid = [&](auto self, int l, int r, int p) -> void{
            if(l == r){
                info[p] = init_[l];
                return ;
            }
            int mid = (l + r) >> 1;
            self(self, l, mid, p << 1);
            self(self, mid + 1, r, p << 1 | 1);
            up(p);
        };
        bulid(bulid, 1, n, 1);
    }
    void cg(int p, const Tag &v){
        info[p].apply(v);
        tag[p].apply(v);
    }
    void up (int p){
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void down (int p){
        cg(p << 1, tag[p]);
        cg(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }
    void update(int l, int r, int x, const Info &v, int p){
        if(l == r){
            info[p] = v;
            return ;
        }
        down(p);
        int mid = (l + r) >> 1;
        if(x <= mid)update(l, mid, x, v, p << 1);
        else update(mid + 1, r, x, v, p << 1 | 1);
        up(p);
    }
    void update(int x, const Info &v){
        update(1, n, x, v, 1);
    }
    Info rangeQuery(int l, int r, int x, int y, int p){
        if(x <= l && r <= y)return info[p];
        Info res = Info();
        down(p);
        int mid = (l + r) >> 1;
        if(x <= mid)res = res + rangeQuery(l, mid, x, y, p << 1);
        if(y > mid)res = res + rangeQuery(mid + 1, r, x, y, p << 1 | 1);
        return res;
    }
    Info rangeQuery(int l, int r){
        return rangeQuery(1, n, l, r, 1);
    }
    void rangeUpdate(int l, int r, int x, int y, const Tag &val, int p){
        if(x <= l && r <= y){
            cg(p, val);
            return ;
        }
        down(p);
        int mid = (l + r) >> 1;
        if(x <= mid)rangeUpdate(l, mid, x, y, val, p << 1);
        if(y > mid)rangeUpdate(mid + 1, r, x, y, val, p << 1 | 1);
        up(p);
    }
    void rangeUpdate(int l, int r, const Tag &val){
        rangeUpdate(1, n, l, r, val, 1);
    }
    template<class F>
    int findFirst(int l, int r, int x, int y, int p, F &&check){
        if(x <= l && r <= y){
            if(!check(info[p]))return -1;
            if(l == r)return l;
        }
        down(p);
        int mid = (l + r) >> 1;
        if(x <= mid){
            int res = findFirst(l, mid, x, y, p << 1, check);
            if(res != -1)return res;
        }
        if(y > mid)return findFirst(mid + 1, r, x, y, p << 1 | 1, check);
        return -1;
    }
    template<class F>
    int findFirst(int l, int r, F &&check){
        return findFirst(1, n, l, r, 1, check);
    }
    template<class F>
    int findLast(int l, int r, int x, int y, int p, F &&check){
        if(x <= l && r <= y){
            if(!check(info[p]))return -1;
            if(l == r)return l;
        }
        down(p);
        int mid = (l + r) >> 1;
        if(y > mid){
            int res = findLast(mid + 1, r, x, y, p << 1 | 1, check);
            if(res != -1)return res;
        }
        if(x <= mid)return findLast(l, mid, x, y, p << 1, check);
        return -1;
    }
    template<class F>
    int findLast(int l, int r, F &&check){
        return findLast(1, n, l, r, 1, check);
    }
};
struct Tag{
    int add = 0;
    void apply(Tag t){
        add += t.add;
    }
};
struct Info{
    int val = 0;
    int lid = 0;
    int rid = 0;
    int l = 0;
    int r = 0;
    int mx = 0;
    void apply(Tag t){
        mx += t.add;
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    if(a.l == 0){
        res.l = b.l;
        res.r = b.r;
        res.mx = b.mx;
        res.lid = b.lid;
        res.rid = b.rid;
        res.val = b.val;
        return res;
    }
    res.l = a.l;
    res.r = b.r;
    res.mx = max(a.mx, b.mx);
    if(a.mx > b.mx){
        int len1 = a.r - a.rid;
        int len2 = b.r - a.rid;
        res.val = a.val - len1 * (len1 + 1) / 2 + len2 * (len2 + 1) / 2;
        res.lid = a.lid;
        res.rid = a.rid;
    }else if(a.mx < b.mx){
        int len1 = b.lid - b.l;
        int len2 = b.lid - a.l;
        res.val = b.val - len1 * (len1 + 1) / 2 + len2 * (len2 + 1) / 2;
        res.lid = b.lid;
        res.rid = b.rid;
    }else{
        int len1 = a.r - a.rid;
        int len2 = b.lid - b.l;
        int len3 = b.lid - a.rid - 1;
        // dbg(len3);
        res.val = a.val + b.val - len1 * (len1 + 1) / 2 - len2 * (len2 + 1) / 2 + len3 * (len3 + 1) / 2;
        res.lid = a.lid;
        res.rid = b.rid;
    }
    return res;
}
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    LazySegmentTree<Info, Tag> tr(n);
    for(int i = 1; i <= n; i++){
        tr.update(i, {0, i, i, i, i, a[i]});
    }
    // dbg(tr.rangeQuery(4, 5).val);
    for(int i = 1; i <= m; i++){
        int ty; cin >> ty;
        if(ty == 1){
            int x, val; cin >> x >> val;
            tr.update(x, {0, x, x, x, x, val});
        }else if(ty == 2){
            int l, r, x; cin >> l >> r >> x;
            tr.rangeUpdate(l, r, {x});
        }else{
            int l, r; cin >> l >> r;
            int len = (r - l + 1);
            int ans = len * (len + 1) / 2;
            // dbg(info.l, info.r);
            // dbg(info.lid, info.rid);
            // dbg(info.mx);
            ans -= tr.rangeQuery(l, r).val;
            cout << ans << '\n';
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}