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
void solve(){
    int n, k; cin >> n >> k;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<>());
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1)ans += a[i];
		else ans -= a[i];
	}
	int sum = 0;
	for(int i = 2; i <= n; i += 2){
		sum += abs(a[i] - a[i - 1]);
	}
	sum = min(sum, k);
	ans -= sum;
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}