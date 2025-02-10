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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int w = a[1];
    vector<int> b(m + 1);
	for(int i = 1; i <= m; i++) cin >> b[i];
	sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());
	vector<int> val(m + 1);
	int p = n;
	for(int i = m; i >= 1; i--){
		while(p >= 1 && a[p] >= b[i])p--;
		val[i] = n - p + 1;
	}
	for(int i = 1; i <= m; i++){
		if(b[i] <= w) val[i] = 1;
	}
	sort(val.begin() + 1, val.end());
	// dbg("???");
	// vector st(21, vector<int>(m + 1));
	// for(int i = 1; i <= m; i++){
	// 	st[0][i] = val[i];
	// }
	// for(int s = 1; s <= 20; s++){
	// 	for(int i = 1; i + (1 << s) <= m + 1; i++){
	// 		st[s][i] = max(st[s - 1][i], st[s - 1][i + (1 << (s - 1))]);
	// 	}
	// }
	// auto get = [&](int l, int r) -> int{
	// 	int d = __lg(r - l + 1);
	// 	return max(st[d][l], st[d][r - (1 << d) + 1]);
	// };
	for(int i = 1; i <= m; i++){
		int sum = 0;
		for(int j = 1; j + i - 1 <= m; j += i){
			sum += val[j + i - 1];
		}
		cout << sum << ' ';
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
总和不可能比 它大的人还高
最多相同，
所以我让相同的尽可能多
那么都小的放在一起
都大的放在一起
剩下模拟？
k = 1?
比a1 小于等于 就是1
如果比a1大，数a中有比它大就是2 否则是1

先放比它小的， 再放比它的大小的
*/