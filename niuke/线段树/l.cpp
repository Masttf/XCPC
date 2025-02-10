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
    	// dbg(l, r);
    	// dbg(info[p].l0, info[p].l1);
    	// dbg(info[p].r0, info[p].r1);
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
	int lz1 = -1;
	int lz2 = 0;
    void apply(Tag t){
    	if(lz2){
    		if(t.lz1 != -1)lz1 = 1 ^ t.lz1;
    	}else{
    		if(t.lz1 != -1)lz1 = t.lz1;
    	}
    	lz2 ^= t.lz2;
    }
};
struct Info{
	int l0 = 0;
	int r0 = 0;
	int mx0 = 0;
	int sum0 = 0;
	int l1 = 0;
	int r1 = 0;
	int mx1 = 0;
	int sum1 = 0;
	int len = 0;
    void apply(Tag t){
    	if(t.lz1 == 0){
    		l0 = r0 = mx0 = sum0 = len;
    		l1 = r1 = mx1 = sum1 = 0;
    	}else if(t.lz1 == 1){
    		l0 = r0 = mx0 = sum0 = 0;
    		l1 = r1 = mx1 = sum1 = len;
    	}
    	if(t.lz2 == 1){
    		swap(l0, l1);
    		swap(r0, r1);
    		swap(mx0, mx1);
    		swap(sum0, sum1);
    	}
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.sum0 = a.sum0 + b.sum0;
    res.sum1 = a.sum1 + b.sum1;
    res.mx0 = max({a.mx0, b.mx0, a.r0 + b.l0});
    res.mx1 = max({a.mx1, b.mx1, a.r1 + b.l1});
    res.len = a.len + b.len;
    res.l0 = a.l0;
    res.l1 = a.l1;
    if(a.l0 == a.len)res.l0 += b.l0;
    if(a.l1 == a.len)res.l1 += b.l1;

    res.r0 = b.r0;
    res.r1 = b.r1;
    if(b.r0 == b.len)res.r0 += a.r0;
    if(b.r1 == b.len)res.r1 += a.r1;
    return res;
}
void solve(){
    int n, q; cin >> n >> q;
    LazySegmentTree<Info, Tag> tr(n);
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	if(x == 1){
    		tr.update(i, {0, 0, 0, 0, 1, 1, 1, 1, 1});
    	}else{
    		tr.update(i, {1, 1, 1, 1, 0, 0, 0, 0, 1});
    	}
    }
    for(int i = 1; i <= q; i++){
    	int op, l, r; cin >> op >> l >> r;
    	l++;
    	r++;
    	if(op <= 1){
    		tr.rangeUpdate(l, r, {op, 0});
    	}else if(op == 2){
    		tr.rangeUpdate(l, r, {-1, 1});
    	}else if(op == 3){
    		cout << tr.rangeQuery(l, r).sum1 << '\n';
    	}else{
    		cout << tr.rangeQuery(l, r).mx1 << '\n';
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