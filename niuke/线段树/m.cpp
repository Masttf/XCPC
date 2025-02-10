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
template<class Info>
struct SegmentTree{
	int n;
	vector<Info> info;
	SegmentTree() : n(0) {}
	SegmentTree(int n_, Info v_ = Info()){
		init(n_, v_);
	}
	template<class T>
	SegmentTree(vector<T> init_){ //注意下标从1开始也就是[0] 是空
		init(init_);
	}
	void init(int n_, Info v_ = Info()){
		init(vector(n_ + 1, v_));
	}
	template<class T>
	void init(vector<T> init_){
		n = init_.size() - 1;
		info.assign(n * 4, Info());
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
	void up (int p){
		info[p] = info[p << 1] + info[p << 1 | 1];
	}
	void update(int l, int r, int x, const Info &v, int p){
		if(l == r){
			info[p] = v;
			return ;
		}
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
		int mid = (l + r) >> 1;
		if(x <= mid)res = res + rangeQuery(l, mid, x, y, p << 1);
		if(y > mid)res = res + rangeQuery(mid + 1, r, x, y, p << 1 | 1);
		return res;
	}
	Info rangeQuery(int l, int r){
		return rangeQuery(1, n, l, r, 1);
	}
	template<class F>
	int findFirst(int l, int r, int x, int y, int p, F &&check){
		if(x <= l && r <= y){
			if(!check(info[p]))return -1;
			if(l == r)return l;
		}
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
constexpr int maxn = 1e5 + 5;
constexpr int inf = 1e9;
int r1[maxn], r2[maxn], c[maxn];
struct Info{
	int l = 0, r = 0;
	int dp[2][2] = {{inf, inf}, {inf, inf}};	
};
Info operator+(const Info &a, const Info &b){
	Info res = Info();
	if(a.l == 0){
		res = b;
	}else{
		res.l = a.l;
		res.r = b.r;
		int x0 = r1[a.r], x1 = r2[a.r];
		int y0 = c[a.r], y1 = c[b.l];
		bool leafL = (a.l == a.r);
		bool leafR = (b.l == b.r);
		if(leafL && leafR){//特判:左右都是叶子节点
			res.dp[0][1] = x0 + x1 + y1;
			res.dp[1][0] = x0 + x1 + y0;
			res.dp[1][1] = y0 + y1 + min(x0,x1);
			return res;
		}
		else if(leafL){//特判:左儿子是叶子节点
			res.dp[0][0] = x0 + x1 + min(b.dp[0][0], b.dp[1][0]);
			res.dp[0][1] = x0 + x1 + min(b.dp[0][1], b.dp[1][1]);
			res.dp[1][0] = y0 + min(min(b.dp[0][0], b.dp[1][0]) + min(x0, x1), x1 + x0 + b.dp[1][0] - y1);
			res.dp[1][1] = y0 + min(min(b.dp[0][1], b.dp[1][1]) + min(x0, x1), x1 + x0 + b.dp[1][1] - y1);
			return res;
		}
		else if(leafR){//特判:右儿子是叶子节点
			res.dp[0][0] = x0 + x1 + min(a.dp[0][0], a.dp[0][1]);
			res.dp[1][0] = x0 + x1 + min(a.dp[1][0], a.dp[1][1]);
			res.dp[0][1] = y1 + min(min(a.dp[0][0], a.dp[0][1]) + min(x0, x1), x1 + x0 + a.dp[0][1] - y0);
			res.dp[1][1] = y1 + min(min(a.dp[1][0], a.dp[1][1]) + min(x0, x1), x1 + x0 + a.dp[1][1] - y0);
			return res;
		}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				for(int c1 = 0; c1 < 2; c1++){
					for(int c2 = 0; c2 < 2; c2++){
						int tp = a.dp[i][c1] + b.dp[c2][j] + min(x0, x1);
						res.dp[i][j] = min(res.dp[i][j], tp);
						if(c1){
							res.dp[i][j] = min(res.dp[i][j], tp - y0 + max(x0, x1));
						}
						if(c2){
							res.dp[i][j] = min(res.dp[i][j], tp - y1 + max(x0, x1));
						}
					}
				}
			}
		}
	}
	return res;
}
void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i < n; i++){
    	cin >> r1[i];
    }
    for(int i = 1; i < n; i++){
    	cin >> r2[i];
    }
    for(int i = 1; i <= n; i++){
    	cin >> c[i];
    }
    vector<Info> a(n + 1);
    for(int i = 1; i <= n; i++){
    	a[i].l = a[i].r = i;
    	a[i].dp[1][1] = c[i];
    }
    SegmentTree<Info> tr(a);
    for(int i = 1; i <= q; i++){
    	char ty; cin >> ty;
    	if(ty == 'Q'){
    		int l, r; cin >> l >> r;
    		Info res = tr.rangeQuery(l, r);
    		int ans = inf;
    		for(int j = 0; j < 2; j++){
    			for(int k = 0; k < 2; k++){
    				ans = min(ans, res.dp[j][k]);
    			}
    		}
    		cout << ans << '\n';
    	}else{
    		int x0, y0, x1, y1, w; cin >> x0 >> y0 >> x1 >> y1 >> w;
    		if(x0 != x1){
				c[y0] = w;
			}else{
				if(y0 > y1)swap(y0,y1);
				if(x0 == 1)r1[y0] = w;
				else r2[y0] = w;
			}
			Info res = Info();
			res.l = res.r = y0;
			res.dp[1][1] = c[y0];
			tr.update(y0, res);
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