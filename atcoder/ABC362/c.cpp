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
    int n; cin >> n;
    vector<int> ans(n + 1);
    int sum = 0;
    vector<array<int, 3>>a(n + 1);
    int mi = 0, mx = 0;
    for(int i = 1; i <= n; i++){
    	int l, r; cin >> l >> r;
        mi += l;
        mx += r;
    	a[i] = {l, r, i};
    }
    if(mi <= 0 && mx >= 0){
        cout << "Yes\n";
        int sum = mx;
        for(int i = 1; i <= n; i++){
            ans[i] = a[i][1];
            if(ans[i] -= sum){
                sum -= a[i][1];
                ans[i] = max(ans[i], a[i][0]);
                sum += ans[i];
            }
        }
        for(int i = 1; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }else cout << "No\n";
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