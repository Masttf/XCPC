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
    int tot = 0;
    int mx = 1e7;
    auto get = [&](int x) -> int{
        return x * (x - 1) / 2 * 3;
    };
    vector<bool> vis(mx + 1);
    for(int i = 0; i <= mx; i++){
        int res = i + get(i);
        if(res > mx)break;
        vis[res] = true;
    }
    for(int j = 0; j <= mx; j++){
        int d2 = 2 * j + get(j);
        if(d2 > mx)break;
        for(int k = 0; k <= mx; k++){
            int d3 = 3 * k + get(k);
            if(d3 + d2 > mx)break;
            if(vis[mx - d3 - d2])tot++;
        }
    }
    
    cout << tot << '\n';
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