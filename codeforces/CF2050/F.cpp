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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>b(n);
	for(int i = 1; i < n; i++){
		b[i] = abs(a[i] - a[i + 1]);
	}
	vector stMax(21, vector<int>(n + 1)), stMin(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		stMax[0][i] = stMin[0][i] = a[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1ll << k) <= n + 1; i++){
			stMax[k][i] = max(stMax[k - 1][i], stMax[k - 1][i + (1ll << (k - 1))]);
			stMin[k][i] = min(stMin[k - 1][i], stMin[k - 1][i + (1ll << (k - 1))]);
		}
	}
	auto check = [&](int l, int r) -> bool{
		int d = __lg(r - l + 1);
		return max(stMax[d][l], stMax[d][r - (1ll << d) + 1]) == min(stMin[d][l], stMin[d][r - (1ll << d) + 1]);
	};
	vector stGCD(21, vector<int>(n));
	for(int i = 1; i < n; i++){
		stGCD[0][i] = b[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1ll << k) < n + 1; i++){
			stGCD[k][i] = __gcd(stGCD[k - 1][i], stGCD[k - 1][i + (1ll << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return __gcd(stGCD[d][l], stGCD[d][r - (1ll << d) + 1]);
	};
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	if(check(l, r)){
    		cout << 0 << ' ';
    		continue;
    	}
    	r--;
    	cout << get(l, r) << ' ';
    }
    cout << '\n';
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
区间gcd是最小的，题目要求最大
如果区间内所有数都相同，那么m = 0
区间gcd是 %m = 0
如果要 %m = 1,那么就是同减1
可以发现同减的话，相邻数的差值不变
所以就是相邻数差值的gcd

*/