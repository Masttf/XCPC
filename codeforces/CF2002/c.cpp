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
    vector<pair<int, int>>a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first >> a[i].second;
    }
    int xx, yy, tx, ty;cin >> xx >> yy >> tx >> ty;
    int dis = 2e18;
    auto get = [&](int x1, int y1, int x2, int y2) -> int{
    	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    for(int i = 1; i <= n; i++){
    	dis = min(dis, get(tx, ty, a[i].first, a[i].second));
    }
    //dbg(dis);
    int d = get(xx, yy, tx, ty);
    //dbg(d);
    if(d < dis)cout << "Yes\n";
    else cout << "No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}