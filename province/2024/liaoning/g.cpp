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
struct Info{
	int mx = 0, cnt = 0;	
};
Info operator+(const Info &a, const Info &b){
	Info res = Info();
	res.mx = max(a.mx, b.mx);
	if(a.mx == res.mx)res.cnt += a.cnt;
	if(b.mx == res.mx)res.cnt += b.cnt;
	return res;
}
void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector st(21, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	st[0][i] = a[i];
    }
    for(int k = 1; k <= 20; k++){
    	for(int i = 1; i + (1 << k) <= n + 1; i++){
    		st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    	}
    }
    auto get = [&](int l, int r) -> int{
    	int d = __lg(r - l + 1);
    	return max(st[d][l], st[d][r - (1 << d) + 1]);
    };
    SegmentTree<Info> tr(n);
    for(int i = 1; i <= n; i++){
    	tr.update(i, {a[i], 1});
    }
    vector<int> dp(n + 5);
    int ans = 0;
    for(int i = n; i >= 1; i--){
    	int l = i, r = n;
    	int R = i;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(get(i, mid) == a[i]){
    			R = mid;
    			l = mid + 1;
    		}else r = mid - 1;
    	}
    	dp[i] = dp[R + 1];
    	int sum = 0;
    	int pos = tr.findFirst(i, R, [&](const Info &t) -> bool{
    		if(t.mx == a[i]){
    			if(sum + t.cnt < k){
    				sum += t.cnt;
    				return false;
    			}else{
    				return true;
    			}
    		}else{
    			return sum >= k;
    		}
    	});
    	if(pos != -1){
    		dp[i] += R - pos + 1;
    	}
    	ans += dp[i];
    }
    cout << ans << '\n';

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
/*
枚举左端点，log算右端点的贡献
以左端点为最大值
否则就是，另一个的dp值
*/