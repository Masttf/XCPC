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
    map<string, int> vis;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            string s; cin >> s;
            vis[s] = 1;
        }
    }
    int m; cin >> m;
    vector<int> use(10), useless(10);
    for(int i = 1; i <= m; i++){
        string s; cin >> s;
        int pos; cin >> pos;
        if(vis.count(s))use[pos]++;
        else useless[pos]++;
    }
    int mx1 = m;
    int sum = 0;
    for(int i = 1; i <= 5; i++){
        mx1 = min(mx1, use[i] + useless[i]);
        sum += use[i];
    }
    cout << min(mx1, sum) << '\n';
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