#include<bits/stdc++.h>
#define int long long
using namespace std;
#define lowbit(x) ((x) & (-x))
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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(a[i] > k) a[i] = 1;
        else a[i] = -1;
    }
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    int sum = 0;
    int l = -1, r = -1;
    int vl, vr;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        if(sum <= 0){
            l = i;
            break;
        }
    }
    vl = sum;
    sum = 0;
    for(int i = n; i >= 1; i--){
        sum += a[i];
        if(sum <= 0){
            r = i;
            break;
        }
    }
    vr = sum;

    if(l != -1 && r != -1 && l < r){
        cout << "Yes\n";
        return ;
    }
    int mx = -1e18;
    for(int i = 1; i <= n; i++){
        if(pre[i] - mx <= 0){
            cout << "Yes\n";
            return ;
        }
        if(pre[i] <= 0){
            mx = max(mx, pre[i]);
        }
    }
    mx = -1e18;
    sum = 0;
    for(int i = n; i >= 1; i--){
        sum += a[i];
        if(sum - mx <= 0){
            cout << "Yes\n";
            return ;
        }
        if(sum <= 0){
            mx = max(mx, sum);
        }
    }
    
    cout << "No" << '\n';
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