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
    int n,x;cin >> n >> x;
    vector<int>a(n + 5);
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    int ok = 0;
    int num = -1,num1 = -1,num2 = -1;
    for (int i = 1;i < n;i++) {
        if (a[i] + a[i + 1] == x) {
            if (a[i] == a[i + 1]) {
                ok = 1;
                num = a[i];
            }
            else {
                num1 = a[i];
                num2 = a[i + 1];
                ok = 2;
            }
            break;
        }
    }
    if (!ok) {
        for (int i = 1;i <= n;i++) cout << a[i] << ' ';
    }
    else if (ok == 1) {
        vector<int>b;
        int vis = 0,cnt = 0;
        for (int i = 1;i <= n;i++) if (a[i] == num) cnt++;
        for (int i = 1;i <= n;i++) {
            if (a[i] != num) b.push_back(a[i]);
            else if (a[i] == num && !vis) {
                b.push_back(a[i]);
                vis = 1;
                cnt--;
            }
        }
        // for (int i : b) cout << i << ' ';
        // cout << '\n';
        vector<int>ans;
        int len = b.size();
        for (int i = 0;i < len;i++) {
            if (b[i] != num && cnt) {
                if (i > 0 && b[i - 1] == num) {
                    ans.push_back(b[i]);
                    continue;
                }
                ans.push_back(num);
                ans.push_back(b[i]);
                cnt--;
            }
            else if (b[i] == num) {
                ans.push_back(b[i]);
            }
            else if (b[i] != num && cnt == 0) ans.push_back(b[i]);
        }
        if (b[len - 1] != num && cnt) {
            ans.push_back(num);
            cnt--;
        }
        if (cnt) cout << "*";
        else {
            for (int i : ans) cout << i << ' ';
        }
    }
    else {
        vector<int>b;
        int cnt = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i] != num1 && a[i] != num2) b.push_back(a[i]);
            else if (a[i] == num1) b.push_back(a[i]);
            else if (a[i] == num2) cnt++;
        }
        int len = b.size();
        vector<int>ans;
        for (int i = 0;i < len;i++) {
            if (b[i] != num1) {
                if (i == 0) {
                    while (cnt) {
                        ans.push_back(num2);
                        cnt--;
                    }
                    ans.push_back(b[i]);
                }
                else {
                    if (b[i - 1] != num1) {
                        while (cnt) {
                            ans.push_back(num2);
                            cnt--;
                        }
                    }
                    ans.push_back(b[i]);
                }
            }
            else {
                ans.push_back(b[i]);
            }
        }
        if (b[len - 1] != num1) {
            while (cnt) {
                ans.push_back(num2);
                cnt--;
            }
        }
        if (cnt) cout << "*";
        else {
            for (int i : ans) cout << i << ' ';
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