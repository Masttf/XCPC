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
	void rangeUpdate(int l, int r, int x, int y, int val, int p){
		if(x <= l && r <= y){
			info[p].cnt += val;
			if(info[p].cnt == 0){
				if(l == r)info[p].sum = 0;
				else info[p].sum = info[p << 1].sum + info[p << 1 | 1].sum;
			}else{
				info[p].sum = info[p].val;
			}
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)rangeUpdate(l, mid, x, y, val, p << 1);
		if(y > mid)rangeUpdate(mid + 1, r, x, y, val, p << 1 | 1);
		if(info[p].cnt == 0){
			if(l == r)info[p].sum = 0;
			else info[p].sum = info[p << 1].sum + info[p << 1 | 1].sum;
		}else{
			info[p].sum = info[p].val;
		}
		return ;
	}
	void rangeUpdate(int l, int r, int x){
		rangeUpdate(1, n, l, r, x, 1);
		return ;
	}
};
struct Info{
	double sum = 0;
	double val = 0;
	int cnt = 0;
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.sum = a.sum + b.sum;
    res.val = a.val + b.val;
    return res;
}
void solve(){
    int n; cin >> n;
    int test = 0;
    while(n){
    	test++;
    	vector<double>p1;
    	vector<double>p2;
    	vector<array<double, 4>> a(n + 1);
    	vector<array<int, 4>>Q;
    	for(int i = 1; i <= n; i++){
    		double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    		a[i] = {x1, y1, x2, y2};
    		p1.push_back(y1);
    		p1.push_back(y2);
    		p2.push_back(x1);
    		p2.push_back(x2);
    	}
    	sort(p1.begin(), p1.end());
    	p1.erase(unique(p1.begin(), p1.end()), p1.end());
    	sort(p2.begin(), p2.end());
    	p2.erase(unique(p2.begin(), p2.end()), p2.end());
    	auto get = [&](vector<double> &p, double x) -> int{
    		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    	};
    	for(int i = 1; i <= n; i++){
    		auto [x1, y1, x2, y2] = a[i];
    		int xx1 = get(p2, x1);
    		int xx2 = get(p2, x2);
    		int yy1 = get(p1, y1);
    		int yy2 = get(p1, y2);
    		Q.push_back({xx1, yy1, yy2, 1});
    		Q.push_back({xx2, yy1, yy2, -1});		
    	}
    	sort(Q.begin(), Q.end(), [&](array<int, 4> &x, array<int, 4> &y) -> bool{
    		return x[0] < y[0];
    	});
    	SegmentTree<Info> tr(p1.size());
    	for(int i = 1; i < p1.size(); i++){
    		tr.update(i + 1, {0, p1[i] - p1[i - 1], 0});
    	}
    	double ans = 0;
    	int N = Q.size();
    	for(int i = 0; i < N - 1; i++){
    		auto [x, y1, y2, f] = Q[i];
    		tr.rangeUpdate(y1 + 1, y2, f);
    		double len = p2[Q[i + 1][0] - 1] - p2[Q[i][0] - 1];
    		ans += len * tr.info[1].sum;
    	}
    	cout << "Test case #" << test << '\n';
    	cout << fixed << setprecision(2) << "Total explored area: " << ans << '\n';
    	cout << '\n';
    	cin >> n;
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