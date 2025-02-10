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
    	if(tag[p].add == -1)return ;
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
	int add, pos;
	Tag(): add(-1){}
	Tag(int add_, int pos_) : add(add_), pos(pos_){}
    void apply(Tag t){
    	add = t.add;
    	pos = t.pos;
    }
};
struct Info{
	int sum, len, l;
    void apply(Tag t){
    	sum = (t.add + l - t.pos)* len;
    	sum += len * (len - 1) / 2;
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.sum = a.sum + b.sum;
    res.len = a.len + b.len;
    res.l = a.l;
    return res;
}
void solve(){
    int n; cin >> n;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    LazySegmentTree<Info, Tag>tr(n);
	for(int i = 1; i <= n; i++){
		tr.update(i, {a[i], 1, i});
	}
    int q; cin >> q;
    int ans = 0;
	for(int i = 1; i <= q; i++){
		int x, y; cin >> x >> y;
		int pos = tr.rangeQuery(x, x).sum;
		if(pos == y)continue;
		if(pos > y){
			int l = 1, r = x;
			int k = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				int ps = tr.rangeQuery(x - mid + 1, x - mid + 1).sum;
				if(ps < y - mid + 1){
					r = mid - 1;
				}else{
					k = mid;
					l = mid + 1;
				}
			}
			assert(k != -1);
			int tot = k * y - (k - 1) * k / 2;
			ans += tr.rangeQuery(x - k + 1, x).sum - tot;
			tr.rangeUpdate(x - k + 1, x, {y - k + 1, x - k + 1});
		}else{
			int l = 1, r = n - x + 1;
			int k = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				int ps = tr.rangeQuery(x + mid - 1, x + mid - 1).sum;
				if(ps < y + mid - 1){
					k = mid;
					l = mid + 1;
				}else{
					r = mid - 1;
				}
			}
			assert(k != -1);
			int tot = k * y + (k - 1) * k / 2;
			ans += tot - tr.rangeQuery(x, x + k - 1).sum;
			tr.rangeUpdate(x, x + k - 1, {y, x});
		}
	}
	cout << ans << '\n';
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