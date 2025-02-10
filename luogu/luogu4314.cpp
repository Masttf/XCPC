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
constexpr int Max = 1e18;
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
	int ad, as;
	int had, has;
	Tag() : ad(0), as(-Max), had(0), has(-Max){}
	Tag(int ad_, int as_, int had_, int has_) : ad(ad_), as(as_), had(had_), has(has_){}
    void apply(Tag t){
    	if(as == -Max && t.as == -Max){
    		had = max(had, ad + t.had);
    		ad += t.ad;
    	}else if(as == -Max && t.as != -Max){
    		had = max(had, ad + t.had);
    		has = t.has;
    		ad = 0;
    		as = t.as;
    	}else if(as != -Max && t.as == -Max){
    		has = max(has, as + t.had);
    		as += t.ad;
    	}else{
    		has = max(has, max(as + t.had, t.has));
    		as = t.as;
    	}
    }
};
struct Info{
	int mx, hmx;
	Info() : mx(-Max), hmx(-Max){}
	Info(int mx_, int hmx_) : mx(mx_), hmx(hmx_){}
    void apply(Tag t){
    	hmx = max({hmx, mx + t.had, t.has});
    	if(t.as != -Max){
    		mx = t.as;
    	}else mx += t.ad;
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.mx = max(a.mx, b.mx);
    res.hmx = max(a.hmx, b.hmx);
    return res;
}
void solve(){
	int n; cin >> n;
	vector<int>a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	LazySegmentTree<Info, Tag> tr(n);
	for(int i = 1; i <= n; i++){
		tr.update(i, {a[i], a[i]});
	}
	int q; cin >> q;
	while(q--){
		char t; cin >> t;
		if(t == 'Q'){
			int l, r; cin >> l >> r;
			cout << tr.rangeQuery(l, r).mx << '\n';
		}else if(t == 'A'){
			int l, r; cin >> l >> r;
			cout << tr.rangeQuery(l, r).hmx << '\n';
		}else if(t == 'P'){
			int l, r, val; cin >> l >> r >> val;
			tr.rangeUpdate(l, r, {val, -Max, max(0ll, val), -Max});
		}else{
			int l, r, val; cin >> l >> r >> val;
			tr.rangeUpdate(l, r, {0, val, 0, val});
		}
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}