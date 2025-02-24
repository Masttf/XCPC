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
    int n,q;cin >> n >> q;
    vector<int> pw(21);
    vector<int> a(n + 5);
    vector<int> op(n + 5);
    vector<int> res1(n + 5),res2(n + 5),res3(n + 5);
    pw[0] = 1;
    for (int i = 1;i <= 20;i++) pw[i] = pw[i - 1] * 2;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        if (a[i] == 1) op[i] = 1;
        else if (a[i] % 2 == 1) op[i] = 3;
        else {
            for (int j = 1;j <= 20;j++) {
                if (a[i] == pw[j]) op[i] = 2;
            }
        } 
    } 
    for (int i = 1;i <= n;i++) {
        res1[i] = res1[i - 1];
        res2[i] = res2[i - 1];
        res3[i] = res3[i - 1];
        if (op[i] == 1) {
            res1[i]++;
        }
        else if (op[i] == 2) {
            res2[i] += a[i];
        }
        else if (op[i] == 3) {
            res3[i] += a[i];
        }
    }
    while (q--) {
        int l,r;cin >> l >> r;
        int num_one = res1[r] - res1[l - 1];
        int anum = num_one / 2 + num_one % 2 + res2[r] - res2[l - 1];
        int bnum = num_one / 2 + res3[r] - res3[l - 1];
        if (anum > bnum) {
            cout << "A" << '\n';
        }
        else if (anum < bnum) {
            cout << "B" << '\n';
        }
        else {
            cout << "E" << '\n';
        }
     }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}