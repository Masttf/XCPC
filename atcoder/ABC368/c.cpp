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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
	vector<int> val = {1, 1, 3};
	int last = 0;
	for(int i = 1; i <= n; i++){
		while(last != 0 && a[i] > 0){
			a[i] -= val[last];
			last++;
			last %= 3;
			ans++;
		}
		ans += (a[i] / 5) * 3;
		a[i] %= 5;
		while(a[i] > 0){
			a[i] -= val[last];
			last++;
			last %= 3;
			ans++;
		}
		//dbg(i, ans, last);
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}