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
	int mx = 0;
	int pos = 0;
    void apply(Tag t){
    	mx += t.add;
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res = Info();
    res.mx = max(a.mx, b.mx);
    if(b.mx == res.mx) res.pos = b.pos;
    if(a.mx == res.mx) res.pos = a.pos;
    return res;
}
constexpr int inf = 1e9;
void solve(){
    int n; cin >> n;
    vector<array<int, 4>> op;
    vector<int> p;
    p.push_back(inf);
    for(int i = 1; i <= n; i++){
    	int l, r; cin >> l >> r;
    	if(l == r - 1)continue;
    	p.push_back(l + 1);
    	p.push_back(r - 1);
    	p.push_back(r + 1);
    	if(r + 1 <= 1e9){
    		op.push_back({l + 1, r + 1, inf, 1});
    		op.push_back({r, r + 1, inf, -1});
    	}
    	op.push_back({0, l + 1, r - 1, 1});
    	op.push_back({l, l + 1, r - 1, -1});
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    for(auto &[x, l, r, f] : op){
    	l = get(l);
    	r = get(r);
    }
    sort(op.begin(), op.end());
    pair<int, int> ans = {0, 1};
    int mx = 0;
    const int sz = op.size();
    const int len = p.size();
    LazySegmentTree<Info, Tag> tr(len);
    for(int i = 1; i <= len; i++){
    	tr.update(i, {0, i});
    }
    for(int i = 0; i < sz; i++){
    	int j = i;
    	while(j < sz && op[j][0] == op[i][0]){
    		tr.rangeUpdate(op[j][1], op[j][2], {op[j][3]});
    		j++;
    	}
    	if(tr.rangeQuery(1, len).mx > mx){
    		mx = tr.rangeQuery(1, len).mx;
    		ans = {op[i][0], p[tr.rangeQuery(1, len).pos - 1]};
    	}
    	i = j - 1;
    }
    // dbg(mx);
    cout << ans.first << ' ' << ans.second << '\n';
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
/*
1. Li < l < Ri < r ---> Li + 1 <= l <= Ri - 1, Ri + 1 <= r <= 1e9
(Li + 1, Ri + 1), (Li + 1, 1e9)
(Ri - 1, Ri + 1), (Ri - 1, 1e9)

2. l < Li < r < Ri ---> 0 <= l <= Li -1, Li + 1 <= r <= Ri - 1
(0, Li + 1), (0, Ri - 1)
(Li - 1, Li + 1), (Li - 1, Ri - 1);
*/