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

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
	vector<pair<int, int>> mx(n + 1);
	vector<int> s;
	for(int i = 1; i <= n; i++){
		int pos = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
		if(pos == s.size()){
			s.push_back(a[i]);
		}else{
			s[pos] = a[i];
		}
		mx[i] = {s.back(), s.size()};
	}
	int ans = s.size();
	s.clear();
	mx[0] = {-1, 0};
	for(int i = n; i >= 1; i--){
		auto [val, len] = mx[i - 1];
		int pos = lower_bound(s.begin(), s.end(), val + 1, greater<int>()) - s.begin();
		// dbg(i, val + 1, pos);
		ans = max(ans, len + 1 + pos);
		pos = lower_bound(s.begin(), s.end(), a[i], greater<int>()) - s.begin();
		if(pos == s.size()){
			s.push_back(a[i]);
		}else{
			s[pos] = a[i];
		}
		// dbg(i, s.size(), val, len, ans);
		// for(auto x : s){
		// 	cout << x << ' ';
		// }
		// cout << endl;
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
/*
枚举修改哪个点， 最值log求出
修改一个位置，lis最多+1
最优选择点是前面的lis的最大值 + 1
然后匹配 后缀的lis

*/