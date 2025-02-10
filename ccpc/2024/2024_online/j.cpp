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
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i++){
		ans1 ^= a[i];
		ans2 ^= b[i];
	}
	vector<int> d(32);
	auto insert = [&](int x) -> void{
		for(int i = 31; i >= 0; i--){
			if(x >> i & 1){
				if(d[i]){
					x ^= d[i];
				}else{
					d[i] = x;
					break;
				}
			}
		}
	};
	auto query = [&](int &x, int lim) -> void{
		for(int i = lim; i >= 0; i--){
			if(d[i] && (x >> i & 1)){
				x ^= d[i];
			}
		}
	};
	for(int i = 1; i <= n; i++)insert(a[i] ^ b[i]);
	for(int i = 31; i >= 0; i--){
		int t1 = ans1 >> i & 1;
		int t2 = ans2 >> i & 1;
		if(t1 && t2){
			ans1 ^= d[i];
			ans2 ^= d[i];
		}else if(!t1 && !t2)continue;
		else{
			if(!t1)ans1 ^= d[i];
			if(!t2)ans2 ^= d[i];
			query(ans1, i - 1);
			query(ans2, i - 1);
			break;
		}
	}
	cout << min(ans1, ans2) << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}