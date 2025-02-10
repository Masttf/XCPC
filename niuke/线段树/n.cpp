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
struct Fenwick{
	#define lowbit(x) ((x) & (-x))
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
struct node{
    int x, y, w;
    bool operator < (const node &A) const {
        return y < A.y;
    }
};
void solve(){
    int n, w, h; 
    while(cin >> n >> w >> h){
    map<int,int>mpx;
    set<int>x1;
    vector<node> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].x >> a[i].y >> a[i].w;
        x1.insert(a[i].x);
        x1.insert(a[i].x - 1);
        x1.insert(a[i].x - w);
        x1.insert(a[i].x + w - 1);
    }
    int cnt = 0;
    for(auto t : x1){
        mpx[t] = ++cnt;
    }
    Fenwick<int> tr(cnt);
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for(int i = 1, j = 1; i <= n; i++) {
        while(j <= n && a[i].y - h >= a[j].y){
            tr.add(mpx[a[j].x], -a[j].w);
            j++;
        }        
    
        tr.add(mpx[a[i].x], a[i].w);
        ans = max({ans, tr.ask(mpx[a[i].x]) - tr.ask(mpx[a[i].x - w]), tr.ask(mpx[a[i].x + w - 1]) - tr.ask(mpx[a[i].x - 1])});
    }
    cout << ans << '\n';
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
