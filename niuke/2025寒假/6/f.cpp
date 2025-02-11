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
	int mx1 = 0, id1 = 0;
	int mx2 = 0, id2 = 0;	
};
Info operator+(const Info &a, const Info &b){
	Info res = Info();
	if(a.mx1 > b.mx1){
		res.mx1 = a.mx1;
		res.id1 = a.id1;
		if(a.mx2 > b.mx1){
			res.mx2 = a.mx2;
			res.mx2 = a.id2;
		}else{
			res.mx2 = b.mx1;
			res.mx2 = b.id1;
		}
	}else{
		res.mx1 = b.mx1;
		res.id1 = b.id1;
		if(b.mx2 > a.mx1){
			res.mx2 = b.mx2;
			res.mx2 = b.id2;
		}else{
			res.mx2 = a.mx1;
			res.mx2 = a.id1;
		}
	}
	return res;
}
void solve(){
	int n; cin >> n;
	vector<pair<int, int>> a(n + 1);
	for(int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		a[i] = {x, y};
	}
	sort(a.begin() + 1, a.end());
	SegmentTree<Info> tr(n);
	for(int i = 1; i <= n; i++){
		auto [x, y] = a[i];
		tr.update(i, {x + y, i, 0, 0});
	}
	auto findFirst = [&](int i, int val) -> int{
		int l = i, r = n;
		int res = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[mid].first <= val){
				res = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		return res;
	};
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		auto [x, y] = a[i];
		
		st[0][i] = tr.rangeQuery(i, res).id1;
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i <= n; i++){
			st[k][i] = st[k - 1][st[k - 1][i]];
		}
	}
	int ans = a[n].first;
	for(int i = 2; i <= n; i++){
		int v = tr.rangeQuery(1, i - 1).id1;

		ans = max(ans, a[v].first + a[v].second);
		int vv = st[20][v];
		if(vv == i){ // 这时候应该用第二大

		}else{
			ans = max(ans, a[vv].first + a[vv].second);
		}
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
假设已知第一个ai
设当前的最大为mx
那么后面只要， ai <= mx 都可以被更新 ai + bi
那么我先按ai sort
预处理 一个变成ai + bi 后能连锁的最远距离
*/