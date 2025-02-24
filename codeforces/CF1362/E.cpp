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
constexpr int mod = 1e9 + 7;
int qmi(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
constexpr int N = 1e6 + 5;
int cnt[N];
bool vis[N];
void solve(){
    int n, p; cin >> n >> p;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(p == 1){
    	cout << n % 2 << '\n';
    	return ;
    }
    sort(a.begin() + 1, a.end());
	set<int> q;
	set<int, greater<int>> roll;
	for(int i = 1; i <= n; i++){
		int j = i;
		while(j <= n && a[j] == a[i])j++;
		cnt[a[i]] = j - i;
		if(cnt[a[i]] >= p)q.insert(a[i]);
		roll.insert(a[i]);
		i = j - 1;
	}
	
	while(!q.empty() && *q.begin() < N){
		int u = *q.begin();
		q.erase(q.begin());
		roll.insert(u + 1);
		cnt[u + 1] += cnt[u] / p;
		vis[u + 1] = 1;
		cnt[u] %= p;
		if(cnt[u + 1] >= p)q.insert(u + 1);
	}
	int ans1 = 0, ans2 = 0;
	for(auto it = roll.begin(); it != roll.end(); it++){
		int i = *it;
		if(cnt[i] % 2 != 0){
			if(vis[i]){
				cnt[i - 1] += p;
				roll.insert(i - 1);
				continue;
			}
			ans1 = qmi(p, i);
			auto j = it;
			j++;
			// dbg(i);
			for(; j != roll.end(); j++){
				int x = *j;
				ans2 = (ans2 + cnt[x] * qmi(p, x) % mod) % mod;
			}
			break;
		}
	}
	int res = ((ans1 - ans2) % mod + mod) % mod;
	cout << res << '\n';
	for(auto x : roll){
		cnt[x] = 0;
		vis[x] = 0;
	}
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
出现偶数次 不用管，可以抵消也可以用来缩小差距
奇数次，
从最高位开始 如果是偶数次不用管，
奇数次 1，然后对面一定要凑出来这个1，p进制下

多测tle？

*/