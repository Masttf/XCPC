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
	int N = 2e5;
	vector<int> cnt(N + 10);
	for(int i = 1; i <= n; i++){
		cnt[a[i]]++;
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			// dbg(j);
			int x = j ^ i;
			if(x > N)continue;
			if(__gcd(x, j) == i){
				ans += cnt[x] * cnt[j];
			}
		}
	}
	ans /= 2;
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
i < j
ai ^ aj == __gcd(ai, aj)

如果 aj 是奇数
ai 是奇数
因为 ai ^ aj 一定是偶数
0

ai 是偶数
ai ^ aj 是奇数
__gcd是奇数

3 * 9 = 27
2 * 9 = 18
10010
01001
 = 11011
   10010
   01001

假设 __gcd(ai, aj) = k
ai ^ aj = k
aj = ai ^ k
__gcd(ai, ai ^ k) = k

ai = d1 * k
ai ^ k = d2 * k
__gcd(d1, d2) = 1

ai < 2e5
能不能预处理什么东西
k < 2e5
暴力枚举 k


*/