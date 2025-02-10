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
    LazySegmentTree(const vector<T>& init_){ //注意下标从1开始也就是[0] 是空
        init(init_);
    }
    void init(int n_, Info v_ = Info()){
        init(vector(n_ + 1, v_));
    }
    template<class T>
    void init(const vector<T>& init_){
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
    int as;
    Tag() : as(-1){}
    Tag(int _as) : as(_as) {}
    void apply(Tag t){
        if(t.as != -1) as = t.as;
    }
};
struct Info{
    int sum, mx, len;
    Info() : sum(0), mx(0), len(1){}
    Info(int _sum, int _mx, int _len) : sum(_sum), mx(_mx), len(_len){}
    void apply(Tag t){
        if(t.as != -1){
            sum = len * t.as;
            mx = t.as;
        }
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.sum = a.sum + b.sum;
    res.len = a.len + b.len;
    res.mx = max(a.mx, b.mx);
    return res;
}
constexpr int maxn = 1e6 + 5;
LazySegmentTree<Info, Tag> tr(maxn);
void solve(){
    int n, p, q; cin >> n >> p >> q;
    vector<pair<int, int>>a(n + 1);
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin() + 1, a.end(), [&](pair<int, int>x, pair<int, int> y) -> bool{
        if(x.first != y.first)return x.first < y.first;
        return x.second > y.second;
    });
    vector<int>res;
    int ans = (p + 1) * (1 + q) * q / 2 + (q + 1) * (1 + p) * p / 2;
    int last = 0;
    for(int i = 1; i <= n; i++){
        ans -= max(0ll, (min(p, a[i].first) - last )) * tr.rangeQuery(1, q).sum;
        int j = i;
        while(j <= n && a[j].first == a[i].first){
            int y = a[j].second;
            int len = 0;
            int ps = lower_bound(res.begin(), res.end(), y) - res.begin();
            if(ps == res.size()){
                res.push_back(y);
            }else{
                res[ps] = y;
            }
            len = ps + 1;
            if(y + 1 <= q){
                int r;
                if(len >= res.size())r = q;
                else r = res[ps];
                // int r = tr.findFirst(y + 1, q, [&](const Info &t) -> bool{
                //  return t.mx > len;
                // });
                // if(r == -1)r = q;
                // else r--;
                if(y < r)tr.rangeUpdate(y + 1, r, {len});
            }
            j++;
        }
        last = a[i].first;
        i = j - 1;
    }
    ans -= max(0ll, p - last) * tr.rangeQuery(1, q).sum;
    cout << ans << '\n';
    tr.rangeUpdate(1, q, {0});
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}