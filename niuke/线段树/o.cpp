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
	int B = sqrt(n);
	vector<int> sum(n / B + 1);
	vector<int> a(n + 1);
	auto add = [&](int x, int val) -> void{
	    int pos = x / B;
	    sum[pos] += val;
	    a[x] += val;
	};
	auto ask = [&](int l, int r) -> int{
	    int res = 0;
	    if(l / B == r / B){
	        for(int i = l; i <= r; i++){
	            res += a[i];
	        }
	    }else{
	        for(int i = l / B + 1; i <= r / B - 1; i++){
	            res += sum[i];
	        }
	        for(int i = l; i < min(n + 1, (l / B + 1) * B); i++){
	            res += a[i];
	        }
	        for(int i = max(1ll, r / B * B); i <= r; i++){
	            res += a[i];
	        }
	    }
	    return res;
	};
	vector<int> lazy(B + 1);
	for(int i = 1; i <= q; i++){
		int op; cin >> op;
		if(op == 1){
			int d, k; cin >> d >> k;
			if(d <= B)lazy[d] += k;
			else{
				for(int j = d; j <= n; j += d){
					add(j, k);
				}
			}
		}else{
			int l, r; cin >> l >> r;
			int ans = ask(l, r);
			for(int j = 1; j <= B; j++){
				ans += (r / j - (l + j - 1) / j + 1) * lazy[j];
			}
			cout << ans << '\n';
		}
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