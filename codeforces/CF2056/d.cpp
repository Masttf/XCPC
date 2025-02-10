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
    int ans = n * (1 + n) / 2;
	vector<int> pre(n + 1);
	for(int i = 1; i <= 10; i++){
		map<int, int> mp;
		pre.assign(n + 1, 0);
		int l = 1;
		for(int j = 1; j <= n; j++){
			if(a[j] == i){
				while(l <= j){
					mp[pre[l - 1]]++;
					l++;
				}	
			}
			pre[j] += pre[j - 1];
			if(a[j] <= i)pre[j]--;
			else pre[j]++;
			if(mp.count(pre[j]))ans -= mp[pre[j]];

		}
		// dbg(i, ans);
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
所有的奇数都可以

偶数
pre r - pre(l - 1)
mid = (r - l) / 2
pos[mid] == pos[mid + 1]
先枚举中位数是哪个 x
1-10
< x 的计数
2 * (pre r - pre l) < r - l - 1
<= x 的计数
2 * (pre r - pre l) >= r - l + 1

2 * pre r - r < 2 * pre l - l -1
v1j - v1i < -1
v2j - v2i >= 1

*/