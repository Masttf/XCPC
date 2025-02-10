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
    vector<int>b(n);
    for(int i = 1; i< n; i++) cin >> b[i];
	for(int j = 30; j >= 0; j--){
		for(int i = 1; i < n; i++){
			if(b[i] >> j & 1){
				a[i] |= (1ll << j);
				a[i + 1] |= (1ll << j);
			}
		}
	}
	int ok = 1;
	for(int i = 1; i < n;i++){
		if(b[i] != (a[i]&a[i + 1]))ok = 0;
	}
	if(ok){
		for(int i =1;i <= n;i ++){
			cout << a[i] << ' ';
		}
		cout << '\n';
	}else cout << -1 << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}