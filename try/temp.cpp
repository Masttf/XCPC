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
	vector<int> tag(n / B + 1);
	vector<int> sum(n / B + 1);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		sum[i / B] += a[i];
	}
	auto add = [&](int l, int r, int val) -> void{
		if(l / B == r / B){
			for(int i = l; i <= r; i++){
				a[i] += val;
				sum[i / B] += val;
			}
		}else{
			for(int i = l / B + 1; i <= r / B - 1; i++){
				tag[i] += val;
				sum[i] += (min(n + 1, (i + 1) * B) - max(1ll, i * B)) * val;
			}
			for(int i = l; i < min(n + 1, (l / B + 1) * B); i++){
				a[i] += val;
				sum[i / B] += val;
			}
			for(int i = max(1ll, r / B * B); i <= r; i++){
				a[i] += val;
				sum[i / B] += val;
			}
		}
	};
	auto ask = [&](int l, int r) -> int{
		int res = 0;
		if(l / B == r / B){
			for(int i = l; i <= r; i++){
				res += a[i] + tag[i / B];
			}
		}else{
			for(int i = l / B + 1; i <= r / B - 1; i++){
				res += sum[i];
			}
			for(int i = l; i < min(n + 1, (l / B + 1) * B); i++){
				res += a[i] + tag[i / B];
			}
			for(int i = max(1ll, r / B * B); i <= r; i++){
				res += a[i] + tag[i / B];
			}
		}
		return res;
	};
	for(int i = 1; i <= q; i++){
		int ty; cin >> ty;
		if(ty == 1){
			int l, r, x; cin >> l >> r >> x;
			add(l, r, x);
		}else{
			int l, r; cin >> l >> r;
			cout << ask(l, r) << '\n';
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