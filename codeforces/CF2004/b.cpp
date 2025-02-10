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
    int l1, r1;cin >> l1 >> r1;
    int l2, r2;cin >> l2 >> r2;
    int l = max(l1, l2);
    int r = min(r1, r2);
    if(l > r){
    	cout << 1 << '\n';
    	return ;
    }
    int ans = r - l + 2;
    if(l1 == l2)ans--;
    if(r1 == r2)ans--;
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