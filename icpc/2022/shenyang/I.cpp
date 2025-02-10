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
	int sz;
	int val[4];
};
Info operator+(const Info &a, const Info &b){
	Info res = Info();
	for(int i = 0; i < 4; i++){
		res.val[i] += a.val[i];
		res.val[(i + a.sz) % 4] += b.val[i];
	}
	res.sz = a.sz + b.sz;
	return res;
}
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i] >> b[i];
    	sum += b[i];
    }
    int N = 2e5;
    int M = 1e5;
    SegmentTree<Info> st(N);
    auto add = [&](int x, int v) -> void{
    	Info temp = st.rangeQuery(x, x);
    	temp.sz++;
    	temp.val[temp.sz % 4] += x - M;
    	st.update(x, temp);
    };
    auto del = [&](int x, int v) -> void{
    	Info temp = st.rangeQuery(x, x);
    	temp.val[temp.sz % 4] -= x - M;
    	temp.sz--;
    	st.update(x, temp);
    };
    for(int i = 1; i <= n; i++){
    	int d = a[i] - b[i] + M;
    	add(d, b[i]);
    }
    Info r1 = st.rangeQuery(1, M - 1);
    Info r2 = st.rangeQuery(M, N);
    int ans = r1.val[0] + r1.val[1] + sum;
    if(r1.sz % 2 == 0)ans += r2.val[1] + r2.val[3];
    else ans += r2.val[0] + r2.val[2];
    cout << ans << '\n';
    for(int i = 1; i <= m; i++){
    	int t, x, y; cin >> t >> x >> y;
    	sum += y - b[t];
    	del(a[t] - b[t] + M, b[t]);
    	a[t] = x; b[t] = y;
    	add(a[t] - b[t] + M, b[t]);
    	r1 = st.rangeQuery(1, M - 1);
    	r2 = st.rangeQuery(M, N);
    	ans = r1.val[0] + r1.val[1] + sum;
    	if(r1.sz % 2 == 0)ans += r2.val[1] + r2.val[3];
    	else ans += r2.val[0] + r2.val[2];
    	cout << ans << '\n';
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