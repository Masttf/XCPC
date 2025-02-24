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
	int miR, mxL;	
};
Info operator+(const Info &a, const Info &b){
	Info res = Info();
	res.miR = min(a.miR, b.miR);
	res.mxL = max(a.mxL, b.mxL);
	return res;
}
void solve(){
    int n; cin >> n;
    vector<int>L(n + 5), R(n + 5);
    for(int i = 1; i <= n; i++) cin >> L[i] >> R[i];
    SegmentTree<Info> tr(n);
	for(int i = 1; i <= n; i++){
		tr.update(i, {R[i], L[i]});
	}
	auto get = [&](int now, int val) -> int{
		int l1 = tr.findFirst(now, n, [&](const Info &t) -> bool{
			return t.mxL > val;
		});
		int l2 = tr.findFirst(now, n, [&](const Info &t) -> bool{
			return t.miR < val;
		});
		if(l1 == -1)l1 = n + 1;
		if(l2 == -1)l2 = n + 1;
		return min(l1, l2);
	};
	vector st(2, vector(21, vector<array<int, 3>>(n + 5)));
	st[0][0][n + 1] = st[1][0][n + 1] = {n + 1, 0, 0};
	for(int i = 1; i <= n; i++){
		int ll = get(i, L[i]);
		if(L[i] > R[ll])st[0][0][i] = {ll, 1, L[i] - R[ll]};
		else st[0][0][i] = {ll, 0, L[ll] - L[i]};
		int rr = get(i, R[i]);
		if(R[i] < L[rr])st[1][0][i] = {rr, 0, L[rr] - R[i]};
		else st[1][0][i] = {rr, 1, R[i] - R[rr]};
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i <= n + 1; i++){
			auto [l, ty, val] = st[0][k - 1][i];
			st[0][k][i] = st[ty][k - 1][l];
			st[0][k][i][2] += val;
			auto [r, tty, vv] = st[1][k - 1][i];
			st[1][k][i] = st[tty][k - 1][r];
			st[1][k][i][2] += vv;
		}
	}
    int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int s, x, t, y; cin >> s >> x >> t >> y;
		if(s > t){
			swap(s, t);
			swap(x, y);
		}
		int l = get(s, x);
		if(l == -1)l = n + 1;
		if(l > t){
			cout << abs(x - y) + t - s<< '\n';
		}else{
			int ans = t - s;
			int now = l, ty;
			if(x > R[l]){
				ans += x - R[l];
				ty = 1;
			}else{
				ans += L[l] - x;
				ty = 0;
			}
			for(int j = 20; j >= 0; j--){
				auto [v, tty, val] = st[ty][j][now];
				if(v <= t){
					ans += val;
					ty = tty;
					now = v;
				}
			}
			//dbg(i, now, ty, ans);
			if(ty == 0)ans += abs(L[now] - y);
			else ans += abs(R[now] - y);
			cout << ans << '\n';
		}
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}