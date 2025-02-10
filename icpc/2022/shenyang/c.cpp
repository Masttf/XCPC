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
void solve(){
    int n, d; cin >> n >> d;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>p;
	for(int i = 1; i <= n; i++)p.push_back(a[i]);
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	int sz = p.size();
	int ans = 0;
	for(int i = 0; i < sz; i++){
		int res = 0;
		int L = p[i];
		int R = p[i] + d;
		vector<int> val(n + 1);
		for(int j = 1; j <= n; j++){
			val[j] = min(max(a[j], L), R);
			if(j > 1)res += abs(val[j - 1] - val[j]);
		}
		ans = max(ans, res);
		res = 0;
		L = p[i] - d;
		R = p[i];
		for(int j = 1; j <= n; j++){
			val[j] = min(max(a[j], L), R);
			if(j > 1)res += abs(val[j - 1] - val[j]);
		}
		ans = max(ans, res);
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}