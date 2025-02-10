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
    vector<int> b(n + 1);
	for(int i = 1; i <= n; i++) cin >> b[i];
	int ans = 64;
	int mx = 64;
	vector<int>bl(n + 1), br(n + 1);
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = b[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return min(st[d][l], st[d][r - (1 << d) + 1]);
	};
	
	// for(int i = 1; i <= n; i++){
	// 	int l = 1, r = i;
	// 	while(l <= r){
	// 		int mid = (l + r) >> 1;
	// 		if(get(mid, i) == b[i]){
	// 			bl[i] = mid;
	// 			r = mid - 1;
	// 		}else l = mid + 1;
	// 	}
	// 	l = i, r = n;
	// 	while(l <= r){
	// 		int mid = (l + r) >> 1;
	// 		if(get(i, mid) == b[i]){
	// 			br[i] = mid;
	// 			l = mid + 1;
	// 		}else r = mid - 1;
	// 	}
	// }
	
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
每次选一段l， r  范围 ai / min(bl - br)
min bi
如果选到min bi 肯定是越大越好
先找到左右边界

区间一定是包含的关系
最多做64次

*/