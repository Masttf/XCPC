#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int inf = 1e9;
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
	int tag = -inf;
    void apply(Tag t){
    	if(t.tag == -1)tag = -1;
    	else tag = max(t.tag, tag);
    }
};
struct Info{
	int mx = -inf;
    void apply(Tag t){
    	if(t.tag == -1)mx = -inf;
    	else mx = max(mx, t.tag);
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.mx = max(a.mx, b.mx);
    return res;
}
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	// vector dp(n + 1, vector<int>(n + 1, -inf));
	// dp[0][0] = 0;
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		dp[i][j] = max(dp[i - 1][j - 1] + (a[i] == j), dp[i - 1][j]);
	// 	}
	// }
	// cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
	vector<vector<int>> pos(n + 1);
	for(int i = 1; i <= n; i++){
		if(a[i] <= n){
			pos[a[i]].push_back(i);
		}
	}
	LazySegmentTree<Info, Tag> tr(n + 1);
	LazySegmentTree<Info, Tag> tr2(n + 1);
	vector<int> mx(2 * n + 5);
	int ans = 0;
	tr2.rangeUpdate(1, n, {0});
	for(int i = 1; i <= n; i++){
		swap(tr, tr2);
		for(auto x : pos[i]){
			int vx = x - 1;
			int val1 = mx[x - i + n] + 1;
			// dbg(val1);
			if(vx >= 1) val1 = max(mx[x - i + n], tr.rangeQuery(vx, vx).mx) + 1;
			if(val1 > mx[x - i + n]){
				dbg(x, i, val1);
				ans = max(ans, val1);
				mx[x - i + n] = val1;
				// dbg(x, n);
				tr2.rangeUpdate(x, n, {val1});
				// dbg(tr2.rangeQuery(2, 2).mx);
			}
		}
		tr.rangeUpdate(1, n, {-1});
		// dbg(tr.rangeQuery(2, 2).mx);
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
// dpij i match j max val
// dpij <- max(dp i-1 j -1 + (ai == j), dp i-1 j)
// n^2
// -> nlog ?
// <<<<<<< <<<<
// 00010000
// 00011000
// 00011100
// 00011110
// 00011111
// useful ai == j
// 斜线
//  