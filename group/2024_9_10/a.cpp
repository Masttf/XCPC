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
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n / 2; i++){
    	int len = n - (i - 1) * 2;
    	int u = i, d = n - i + 1;
    	int l = i, r = n - i + 1;
    	string s1 = "", s2 = "", s3 = "", s4 = "";
    	for(int j = l; j <= r; j++){
    		s1 += a[u][j];
    	}
    	for(int j = r; j >= l; j--){
    		s4 += a[d][j];
    	}
    	for(int j = d; j >= u; j--){
    		s2 += a[j][l];
    	}
    	for(int j = u; j <= d; j++){
    		s3 += a[j][r];
    	}
    	for(int j = 0; j < len - 1; j++){
    		char mx = max({s1[j], s2[j], s3[j], s4[j]});
    		ans += mx - s1[j] + mx - s2[j] + mx - s3[j] + mx - s4[j];
    	}
    }
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