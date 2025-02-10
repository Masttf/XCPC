#include<bits/stdc++.h>
// #define int long long
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
template<const int T>
struct ModInt {
	const static int mod = T;
	int x;
	ModInt(int x = 0) : x(x < 0 ? x % mod + mod : x % mod) {}
	ModInt(long long x) : x(int(x < 0 ? x % mod + mod : x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { 
		int x0 = x + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod); 
	}
	ModInt operator - (const ModInt &a) const {
		int x0 = x - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}
	ModInt operator * (const ModInt &a) const {
		return ModInt(1LL * x * a.x % mod);
	}
	ModInt operator / (const ModInt &a) const {
		return *this * a.inv();
	}
	bool operator == (const ModInt &a) const {
		return x == a.x;
	}
	bool operator != (const ModInt &a) const {
		return x != a.x;
	}
	void operator += (const ModInt &a) {
		x += a.x;
		if (x >= mod) x -= mod;
	}
	void operator -= (const ModInt &a) {
		x -= a.x;
		if (x < 0) x += mod;
	}
	void operator *= (const ModInt &a) {
		x = 1LL * x * a.x % mod;
	}			
	void operator /= (const ModInt &a) {
		*this = *this / a;
	}
	friend ModInt operator + (int y, const ModInt &a){
		int x0 = y + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	friend ModInt operator - (int y, const ModInt &a){
		int x0 = y - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}			
	friend ModInt operator * (int y, const ModInt &a){
		return ModInt(1LL * y * a.x % mod);
	}
	friend ModInt operator / (int y, const ModInt &a){
		return ModInt(y) / a;
	}
	friend ostream &operator<<(ostream &os, const ModInt &a) {
		return os << a.x;
	}
	friend istream &operator>>(istream &is, ModInt &t){
		return is >> t.x;
	}						
				
	ModInt pow(long long n) const {
	ModInt res(1), mul(x);
		while(n){
			if (n & 1) res *= mul;
			mul *= mul;
			n >>= 1;
		}
		return res;
	}
				
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0;
		while (b) {
			int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0) u += mod;
		return u;
	}
				
};
constexpr int mod = 1e9 + 7;
using mint = ModInt<mod>;
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
	array<mint, 6> tag;
	Tag() : tag({}){}
    Tag(array<mint, 6> _tag) : tag(_tag) {}
    void apply(Tag t){
    	array<mint, 6>temp;
        temp[0] = tag[0] + t.tag[0];
        temp[1] = t.tag[1] + tag[0] * t.tag[3] + tag[1];
        temp[2] = t.tag[2] + tag[0] * t.tag[4] + tag[1] * t.tag[5] + tag[2];
        temp[3] = t.tag[3] + tag[3];
        temp[4] = t.tag[4] + tag[3] * t.tag[5] + tag[4];
        temp[5] = t.tag[5] + tag[5];
        swap(temp, tag);
    }
};
struct Info{
	array<mint, 4>val;
	Info() : val({}) {}
    Info(array<mint, 4> _val) : val(_val) {} 
    void apply(Tag t){
    	array<mint, 4>temp;
        temp[0] = val[0];
        temp[1] = val[1] + val[0] * t.tag[0];
        temp[2] = val[0] * t.tag[1] + val[1] * t.tag[3] + val[2];
        temp[3] = val[0] * t.tag[2] + val[1] * t.tag[4] + val[2] * t.tag[5] + val[3];
        swap(temp, val);
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    for(int i = 0; i < 4; i++){
        res.val[i] = a.val[i] + b.val[i];
    }
    return res;
}
void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
	vector<array<int, 3>> b(m + 1);
	vector<vector<array<int, 4>>> Q(m + 1);
	for(int i = 1; i <= m; i++){
		int l, r, x; cin >> l >> r >> x;
		b[i] = {l, r, x};
	}
	vector<mint> ans(q + 1);
	for(int i = 1; i <= q; i++){
		int l, r, x, y; cin >> l >> r >> x >> y;
		if(x != 0)Q[x - 1].push_back({l, r, -1, i});
		Q[y].push_back({l, r, 1, i});
	}
	LazySegmentTree<Info, Tag> tr(n);
    for(int i = 1; i <= n; i++){
        array<mint, 4> temp = {1, a[i], 1ll * a[i] * a[i] % mod, 1ll * a[i] * a[i] % mod};
        tr.update(i, {temp});
    }
	for(int i = 0; i <= m; i++){
        if(i){
            auto [l, r, x] = b[i];
            array<mint, 6> temp = {};
            temp[5] = 1;
            if(l > 1)tr.rangeUpdate(1, l - 1, {temp});
            if(r < n)tr.rangeUpdate(r + 1, n, {temp});
            temp[0] = x;
            temp[1] = 1ll * x * x % mod;
            temp[2] = 1ll * x * x % mod;
            temp[3] = 2 * x % mod;
            temp[4] = 2 * x % mod;
            tr.rangeUpdate(l, r, {temp});
        }
        for(auto [l, r, f, id] : Q[i]){
            if(f == 1)ans[id] += tr.rangeQuery(l, r).val[3];
            else ans[id] -= tr.rangeQuery(l, r).val[3];
        }
	}
	for(int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
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