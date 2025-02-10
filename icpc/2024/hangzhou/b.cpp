#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
constexpr int Max = (1ull << 63) - 1;
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
	int op = Max;
    void apply(Tag t){
    	if(t.op == Max)return ;
    	op &= t.op;
    }
};
struct Info{
	int statu1 = Max, statu2 = 0, val = Max;
	int l, r;
    void apply(Tag t){
    	if(t.op == Max)return ;
    	statu1 &= t.op;
    	statu2 &= t.op;
    	val &= t.op;
    	if(l == r)statu2 = Max ^ val;
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.statu1 = a.statu1 & b.statu1;
    res.statu2 = (a.statu1 & b.statu2) | (a.statu2 & b.statu1);
    res.val = a.val & b.val;
    res.l = a.l;
    res.r = b.r;
    return res;
}
void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    LazySegmentTree<Info, Tag> tr(n);
	for(int i = 1; i <= n; i++){
		tr.update(i, {a[i], Max ^ a[i], a[i], i, i});
	}
	for(int i = 1; i <= q; i++){
		int ty; cin >> ty;
		if(ty == 1){
			int l, r, x; cin >> l >> r >> x;
			tr.rangeUpdate(l, r, {x});
		}else if(ty == 2){
			int x, val; cin >> x >> val;
			tr.update(x, {val, Max ^ val, val, x, x});
		}else{
			int l, r; cin >> l >> r;
			if(l == r){
				cout << 0 << '\n';
				continue;
			}
			Info res = tr.rangeQuery(l, r);
			// dbg(i, res.statu1, res.statu2);
			int chose = -1;
			if(res.statu2){
				chose = __lg(res.statu2);
			}
			// dbg(chose);
			if(chose == -1){
				cout << res.val << '\n';
			}else{
				int pos = tr.findFirst(l, r, [&](const Info &t) -> bool{
					if(t.statu1 >> chose & 1)return false;
					else return true;
				});
				// assert(pos != -1);
				// dbg(pos);
				int ans = Max;
				if(l < pos)ans &= tr.rangeQuery(l, pos - 1).val;
				if(pos < r)ans &= tr.rangeQuery(pos + 1, r).val;
				cout << ans << '\n';
			}
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