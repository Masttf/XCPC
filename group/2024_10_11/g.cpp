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
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0;
    int cnt3 = 0, cnt4 = 0;
    for(auto x : s){
    	if(x == 'T')cnt1++;
    	else if(x == 'P')cnt2++;
    	else if(x == 'A')cnt3++;
    	else if(x == 'U')cnt4++;
    }
    int ans = min({cnt1, cnt2, cnt3 + cnt4});
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}