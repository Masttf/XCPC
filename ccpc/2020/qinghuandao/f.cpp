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

const int maxn = 3e5 + 5;
int f[maxn],siz[maxn],num[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
} 

void solve(){
    int n,m;cin >> n >> m;
    for (int i = 1;i <= n;i++) f[i] = i,siz[i] = 1,num[i] = 0;
    //dbg(1);
    for (int i = 1;i <= m;i++) {
        int u,v;cin >> u >> v;
        int fu = find(u),fv = find(v);
        if (fu == fv) {
            num[fu]++;
            continue;
        }
        f[fu] = fv;
        siz[fv] += siz[fu]; 
        num[fv] += num[fu];
        num[fv]++;
    }  
    //dbg(1);
    // int ans = 0;
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        int fi = find(i);
        if(i != fi)continue;
        //dbg(num[fi],siz[fi]);
        if(num[fi] - siz[fi] >= 0)sum += num[fi] - siz[fi];
        // ans = max(ans,num[fi] - siz[fi]);
    }
    cout << sum << '\n'; 
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
    return 0;
}