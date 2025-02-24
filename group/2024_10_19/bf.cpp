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


void solve() {
    int n, k;
    std::cin >> n >> k;
    if(k == 1) {
        if(n == 1) cout << "Yes\n";
        else cout << "No\n";
        return ;
    }
    if(k % 2 == 0) {
        cout << "Yes\n";
        return ;
    }
    int x = k / 2 + 1,y = k / 2;
    int dis = n / k;
    int mod = n % k;
    //dbg(dis,mod);
    if (dis <= mod && (mod - dis) % 2 == 0 && dis + (mod - dis) / 2 <= y) {
        cout << "Yes" << '\n';
        return ;
    }    
    else if ((dis - 1) <= mod && (mod - (dis - 1)) % 2 == 0 && dis - 1 + (mod - (dis - 1)) / 2 <= y) {
        cout << "Yes" << '\n';
        return ;
    }
    else {
        cout << "No" << '\n';
        return ;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}