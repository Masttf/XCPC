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
	SegmentTree(vector<T> init_){
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
	int mx, id;
	Info() : mx(0), id(0){}
	Info(int mx_, int id_) : mx(mx_), id(id_){}
};
Info operator+(const Info &a, const Info &b){
	Info res = Info();
	res.mx = max(a.mx, b.mx);
	if(b.mx == res.mx){
		res.id = b.id;
	}
	if(a.mx == res.mx){
		res.id = a.id;
	}
	return res;
}
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> op(n + 1);
    vector<pair<int ,int>>s(k + 5);
    s[0] = {1, 1};
    for(int i = 1; i <= k; i++){
    	int x, y; cin >> x >> y;
    	s[i] = {x, y};
    	op[x].push_back({y, i});
    }
    s[k + 1] = {n, m};
    op[n].push_back({m, k + 1});
    for(int i = 1; i <= n; i++)sort(op[i].begin(), op[i].end());
    vector<int> val(k + 5);
    vector<int> pre(k + 5);
    SegmentTree<Info> tr(m);
    for(int i = 1; i <= n; i++){
    	for(auto [y, id] : op[i]){
    		Info res = tr.rangeQuery(1, y);
    		val[id] = res.mx + 1;
    		pre[id] = res.id;
    		tr.update(y, {res.mx + 1, id});
    	}
    }
    cout << val[k + 1] - 1<< '\n';
    int nx = n, ny = m;
    int now = k + 1;
    vector<char>res;
    while(now != 0){
    	int fa = pre[now];
    	auto [tx, ty] = s[fa];
    	now = fa;
    	while(nx > tx){
    		res.push_back('D');
    		nx--;
    	}
    	while(ny > ty){
    		res.push_back('R');
    		ny--;
    	}
    }
    reverse(res.begin(), res.end());
    for(auto x :res){
    	cout << x;
    }
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}