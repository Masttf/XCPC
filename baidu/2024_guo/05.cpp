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
constexpr int Max = 1e18;
void solve(){
    int n, K, D; cin >> n >> K >> D;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector stMax(21, vector<int>(n + 1)), stMin(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		stMax[0][i] = a[i];
		stMin[0][i] = a[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			stMax[k][i] = max(stMax[k - 1][i], stMax[k - 1][i + (1 << (k - 1))]);
			stMin[k][i] = min(stMin[k - 1][i], stMin[k - 1][i + (1 << (k - 1))]);
		}
	}
	auto get_max = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return max(stMax[d][l], stMax[d][r - (1 << d) + 1]);
	};
	auto get_min = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return min(stMin[d][l], stMin[d][r - (1 << d) + 1]);
	};
	auto check = [&](int lim) -> bool{
		int cnt = 1;
		int mx = -Max, mi = Max;
		for(int i = 1; i <= n; i++){
			mx = max(mx, a[i]);
			mi = min(mi, a[i]);
			if(mx - mi > lim){
				mx = a[i];
				mi = a[i];
				cnt++;
			}
		}
		return cnt <= K;
	};
	int ans1 = Max;
	{
		int l = 0, r = Max;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid)){
				ans1 = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		cout << ans1 << '\n';
	}
	{
		int ans2 = 1;
		int mx = -Max, mi = Max;
		for(int i = 1; i <= n; i++){
			mx = max(mx, a[i]);
			mi = min(mi, a[i]);
			if(mx - mi > D){
				mx = a[i];
				mi = a[i];
				ans2++;
			}
		}
		cout << ans2 << '\n';
	}
	vector st(21, vector<int>(n + 2));
	st[0][n + 1] = n + 1;
	for(int i = 1; i <= n; i++){
		int l = i, r = n;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(get_max(i, mid) - get_min(i, mid) <= D){
				st[0][i] = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		st[0][i]++;

		//dbg(i, st[0][i]);
	}
	for(int k = 1; k <= 20; k++){
		st[k][n + 1] = n + 1;
		for(int i = 1; i <= n; i++){
			st[k][i] = st[k - 1][st[k - 1][i]];
		}
	}
	int ans3 = 0;
	for(int i = 1; i <= n; i++){
		int now = i;
		for(int j = 20; j >= 0; j--){
			if(K >> j & 1){
				now = st[j][now];
			}
		}
		ans3 = max(ans3, now - i);
	}
	cout << ans3 << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}