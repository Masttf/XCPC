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
    auto valid = [&](int x) -> bool{
        int t = x;
        while(t){
            if(t % 10 == 0)return false;
            t /= 10;
        }
        return true;
    };
    auto rev = [&](int x) -> int{
        string t = to_string(x);
        reverse(t.begin(), t.end());
        return stoll(t);
    };
    auto isP = [&](int x) -> bool{
        return x == rev(x);
    };
    auto dfs = [&](auto self, int x) -> string{
        if(valid(x) && isP(x)){
            return to_string(x);
        }
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0 && valid(i) && x / i % rev(i) == 0){
                string t = self(self, x / (i * rev(i)));
                if(!t.empty())return to_string(i) + "*" + t + "*" + to_string(rev(i));
            }
        }
        return "";
    };
    string ans = dfs(dfs, n);
    if(ans.empty())cout << -1 << '\n';
    else cout << ans << '\n';
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