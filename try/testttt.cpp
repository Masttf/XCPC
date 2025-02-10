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
constexpr int inf = 1e18;
constexpr int eps = 1e14;
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
        // dbg(l, r);
    	// dbg(res.l1, res.l2);
    	// dbg(res.r2, res.r1);
    	// dbg(res.ok);
    	// dbg(res.mi);
    	// dbg(res.mx);
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
    void check(int l, int r, int p){
    	dbg(l, r);
    	dbg(info[p].l1, info[p].l2);
    	dbg(info[p].r2, info[p].r1);
    	dbg(info[p].ok);
    	dbg(info[p].mi);
    	dbg(info[p].mx);
    	if(l == r)return ;
    	int mid = (l + r) >> 1;
    	down(mid);
    	check(l, mid, p << 1);
    	check(mid + 1, r, p << 1 | 1);
    }
    void check(){
    	check(1, n, 1);
    }
};
struct Tag{
	int add = 0;
    void apply(Tag t){
    	add += t.add;
    }
};
struct Info{
	int ok = 1;
	int l1 = inf;
	int l2 = inf;
	int r1 = inf;
	int r2 = inf;
	int mi = inf;
	int mx = -inf;
	int num = 0;
    void apply(Tag t){
    	l1 += t.add;
    	l2 += t.add;
    	r1 += t.add;
    	r2 += t.add;
    	mi += t.add;
    	mx += t.add;
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    if(a.l1 >= eps){
    	res = b;
    	return res;
    }
    res.l1 = a.l1;
    res.l2 = a.l2;
    res.r1 = b.r1;
    res.r2 = b.r2;
    if(a.l2 >= eps){
    	if(b.l1 != a.r1)res.l2 = b.l1;
    	else res.l2 = b.l2;
    }
    if(b.r2 >= eps){
    	if(a.r1 != b.l1)res.r2 = a.r1;
    	else res.r2 = a.r2;
    }
    res.ok = a.ok & b.ok;
    if(a.mx >= b.mi)res.ok = 0;
    res.mi = min(a.mi, b.mi);
    res.mx = max(a.mx, b.mx);
    res.num = a.num + b.num;
    if(a.r1 == b.l1)res.num--;
    if(res.num <= 2){
    	return res;
    }
    if(a.r1 == b.l1){
    	if(a.r2 < eps && b.l2 < eps && a.r2 > a.r1 && a.r1 < b.l2){
    		if(!(a.mx < a.r1 && a.r1 < b.mi))res.ok = 0;
    		res.mi = min(res.mi, a.r1);
    		res.mx = max(res.mx, a.r1);
    	}
    }else if(a.r1 < b.l1){
    	if(a.r2 < eps && a.r2 > a.r1){
    		if(!(a.mx < a.r1 && a.r1 < b.mi))res.ok = 0;
    		res.mi = min(res.mi, a.r1);
    		res.mx = max(res.mx, a.r1);
    	}
    }else{
    	if(b.l2 < eps && b.l1 < b.l2){
    		if(!(a.mx < b.l1 && b.l1 < b.mi))res.ok = 0;
    		res.mi = min(res.mi, b.l1);
    		res.mx = max(res.mx, b.l1);
    	}
    }
    return res;
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    LazySegmentTree<Info, Tag> tr(n);
	for(int i = 1; i <= n; i++){
		tr.update(i, {1, a[i], inf, a[i], inf, inf, -inf, 1});
	}
	// tr.check();
    int m; cin >> m;
    for(int i = 1; i <= m; i++){
    	string t; cin >> t;
    	if(t[0] == 'c'){
    		int l, r; cin >> l >> r;
    		if(r - l + 1 <= 2){
    			cout << "YES\n";
    			continue;
    		}
    		auto res = tr.rangeQuery(l, r);
    		// dbg(res.l1, res.l2);
    		// dbg(res.r2, res.r1);
    		// dbg(res.ok);
    		// dbg(res.mi);
    		// dbg(res.mx);
    		if(res.l1 < res.l2){
    			if(res.l1 >= res.mi){
    			 	res.ok = 0;
    			}
    			res.mi = min(res.mi, res.l1);
    			res.mx = max(res.mx, res.l1);
    		}
    		if(res.r1 < res.r2){
    			if(res.r1 <= res.mx)res.ok = 0;
    		}
    		if(res.ok)cout << "YES\n";
    		else cout << "NO\n";
    	}else{
    		int l, r, val; cin >> l >> r >> val;
    		tr.rangeUpdate(l, r, {val});
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