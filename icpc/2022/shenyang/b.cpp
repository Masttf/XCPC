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
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < (1LL << n); ++i) {
        string s;
        int mi = i;
        while(mi) {
            s += mi % 2 + '0';
            mi >>= 1;
        }
        while(s.size() < n) s += '0';
        set<string> ss;
        for(int j = 0; j < n; ++j) {
            string mid;
            for(int k = j; k < n; ++k) {
                mid += s[k];
                ss.insert(mid);
            }
        }
        mp[i] = ss.size();
    }
    int mx = 0;
    for(auto [i, j] : mp) {
        // std::cout << i << ' ' << j << '\n';
        mx = max(mx, j);
    }
    for(auto [i, j] : mp) {
        if(j == mx) {
            bitset<9> bit(i);
            cout << bit << '\n';
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}