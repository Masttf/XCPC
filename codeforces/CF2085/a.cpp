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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if (k == 0){
        if(s < tmp){
            cout << "Yes\n";
            return ;
        }
        cout << "No\n";
        return;
    }
    s = ' ' + s;
    if(s[1] != s[n]){
        cout << "Yes\n";
        return;
    }
    int ok = 0;
    for(int i = 2; i <= n - 1; i++){
        if(s[i] != s[1]){
            ok = 1;
        }
    }
    if(ok)cout << "Yes\n";
    else cout << "No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}