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
struct cmp{
    bool operator() (const array<int, 3> &x, const array<int, 3> &y)const {
        if(x[2] == y[2])return false;
        if(x[0] * y[1] != y[0] * x[1]){
    		return x[1] * y[0] < x[0] * y[1];
    	}else return x[2] < y[2];
    }
};
void solve(){
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 2; i <= n; i++) cin >> p[i];
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector<int> f(n + 1);
    vector<pair<int, int>> val(n + 1, {0, 0});
    for(int i = 1; i <= n; i++){
    	f[i] = i;
    	if(a[i] == 1)val[i].second = 1;
    	else val[i].first = 1;
    } 
    auto find = [&](auto self, int x) -> int{
    	return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    set<array<int, 3>, cmp>s;
    int ans = 0;
    auto merge = [&](int a, int b) -> void{
    	int fa = find(find, a);
    	int fb = find(find, b);
    	if(fa == fb)return ;
    	s.erase({val[fa].first, val[fa].second, fa});
    	s.erase({val[fb].first, val[fb].second, fb});
    	ans += val[fb].second * val[fa].first;
    	f[fa] = fb;
    	val[fb].first += val[fa].first;
    	val[fb].second += val[fa].second;
    	if(fb != 1)s.insert({val[fb].first, val[fb].second, fb});
    };
    for(int i = 2; i <= n; i++){
    	s.insert({val[i].first, val[i].second, i});
    }
    while(!s.empty()){
    	int now = (*s.begin())[2];
    	merge(now, find(find, p[now]));
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