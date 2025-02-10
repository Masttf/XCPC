#include <bits/stdc++.h>

#define int long long
//#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int M = 1e7+5, P = 998244353;

int qpow(int x, int r) {
    int re = 1;
    while(r) {
        if(r&1) re = re * x % P;
        x = x*x%P, r>>=1;
    }
    return re;
}

int fn[M], fd[M], fn2[M];

void pre() {
    fn[0] = fd[0] = fn2[0] = 1;
    fn[1] = fd[1] = fn2[1] = 1;
    for(int i = 2; i < M; i++)
        fn[i] = fn[i-1]*i%P, fn2[i] = fn2[i-2]*i%P;
    fd[M-1] = qpow(fn[M-1], P-2);
    for(int i = M-2; i > 0; i--)
        fd[i] = fd[i+1] * (i+1)%P;
}

int h[30];

void solve() {
    int n, sum=0, cnt=0;
    cin >> n;
    memset(h, 0, sizeof(h));
    for(int i = 1; i <= n; i++) {
        char c; int x;
        cin >> c >> x;
        h[c-'a'] += x;
    }
    for(int i = 0; i < 26; i++)
        sum += h[i], cnt += (h[i]&1);

    if(cnt == 0) {
        int ave = fn2[sum];
        for(int i = 0; i < 26; i++) if(h[i])
            ave = ave * fn2[h[i]-1] % P;
        ave = ave * fd[sum]%P;
        cout << (1-ave+P) * qpow(2, P-2)%P;
    }
    else if(cnt == 1) {
        int ave = 1;
        for(int i = 0; i < 26; i++)
            if(h[i]&1) { ave = h[i]; break; }
        ave = ave*qpow(sum, P-2)%P;

        for(int i = 0; i < 26; i++) if(h[i]) {
            if(!(h[i]&1)) ave = ave * fn2[h[i]-1] % P;
            else if(h[i]>2) ave = ave * fn2[h[i]-2] % P;
        }

        ave = ave*fn2[sum-1]%P;
        ave = ave*fd[sum-1]%P;

        cout << ((1-ave+P) * qpow(2, P-2)%P + ave) %P << endl;
    }
    else {
        cout << qpow(2, P-2) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    int tc = 1;
	cin>>tc;
    while (tc--) solve();
    return 0;
}