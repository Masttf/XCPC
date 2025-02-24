#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
struct Fenwick{
	// #define lowbit(x) ((x) & (-x))
	vector<Info> tr;
	int n;
	Fenwick(int n_) : n(n_), tr(n_ + 1){}
	void add(int x, Info val){
		while(x <= n){
			tr[x] = tr[x] + val;
			x += lowbit(x);
		}
	}
	Info ask(int x){
		Info res = Info();
		while(x > 0){
			res = res + tr[x];
			x -= lowbit(x);
		}
		return res;
	}
	Info rangeAsk(int l, int r){
		return ask(r) - ask(l - 1);
	}
	template<class F>
	int find(F &&check){
		int p = 0;
		Info res = Info();
		int d = __lg(n);
		for(int i = d; i >= 0; i--){
			int v = p + (1ll << i);
			if(v <= n && check(res + tr[v])){
				p = v;
				res = res + tr[p];
			}
		}
		return p;
	}
};
struct Info{
	int sum = 0, cnt = 0;
};
Info operator+ (const Info &a, const Info &b){
	Info res = Info();
	res.sum = a.sum + b.sum;
	res.cnt = a.cnt + b.cnt;
	return res;
}
Info operator- (const Info &a, const Info &b){
	Info res = Info();
	res.sum = a.sum - b.sum;
	res.cnt = a.cnt - b.cnt;
	return res;
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> cnt(n + 1);
	vector<int> val(n + 1);
	Fenwick<int> tr(n);
	for(int i = n; i >= 1; i--){
		// dbg(i, a[i]);
		cnt[a[i]] = tr.ask(a[i]);
		tr.add(a[i], 1);
	}
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += cnt[i];
		val[i] = sum;
	}
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; i++){
		pos[a[i]] = i;
	}
	Fenwick<Info> tr2(n);
	for(int i = 1; i <= n; i++){
		sum = 0;
		tr2.add(pos[i], {pos[i], 1});
		int mid = tr2.find([&](const Info &t) -> bool{
			return t.cnt <= ((i + 1) / 2 - 1);
		});
		mid++;
		Info l = tr2.ask(mid);
		Info r = tr2.rangeAsk(mid + 1, n);
		sum += l.cnt * mid - (l.cnt - 1) * l.cnt / 2 - l.sum;
		sum += r.sum - r.cnt * mid - (r.cnt + 1) * r.cnt / 2;
		cout << sum + val[i] << ' ';
	}
	cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}
/*
f(n) = 逆序对个数
结论应该是先按相对位置排队，然后内部逆序对个数次调整
中位数
动态中位数？？how
每次加入一个数 只会左右移动一个数

但是要求是排队距离最短，要先 - 相对位置，然后中位数
插入一个新数时，会使右边的数都-1

*/