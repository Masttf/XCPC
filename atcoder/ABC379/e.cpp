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
constexpr int N = 2e5 + 5;

struct BigInt {
    int a[N];
    BigInt(int x = 0) : a{} {
        for (int i = 0; x; i++) {
            a[i] = x % 10;
            x /= 10;
        }
    }
    BigInt &operator*=(int x) {
        for (int i = 0; i < N; i++) {
            a[i] *= x;
        }
        for (int i = 0; i < N - 1; i++) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        return *this;
    }
    BigInt &operator/=(int x) {
        for (int i = N - 1; i >= 0; i--) {
            if (i) {
                a[i - 1] += a[i] % x * 10;
            }
            a[i] /= x;
        }
        return *this;
    }
    BigInt &operator+=(const BigInt &x) {
        for (int i = 0; i < N; i++) {
            a[i] += x.a[i];
            if (a[i] >= 10) {
                a[i + 1] += 1;
                a[i] -= 10;
            }
        }
        return *this;
    }
};

std::ostream &operator<<(std::ostream &o, const BigInt &a) {
    int t = N - 1;
    while (a.a[t] == 0) {
        t--;
    }
    for (int i = t; i >= 0; i--) {
        o << a.a[i];
    }
    return o;
}
constexpr int maxn = 5e5 + 5;
int a[maxn];
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; i++){
    	int x = (n - i + 1);
    	int y = i * (s[i] - '0');
    	a[1] += y;
    	a[x + 1] -= y;
    }
    for(int i = 1; i <= n + 1; i++){
    	a[i] += a[i - 1];
    }
    for(int i = 1; i <= n; i++){
    	a[i + 1] += a[i] / 10;
    	a[i] %= 10;
    }
    int cnt = n + 1;
    while(a[cnt] >= 10){
    	a[cnt + 1] += a[cnt] / 10;
    	a[cnt] %= 10;
    	cnt++;
    }
    while(!a[cnt])cnt--;
    for(int i = cnt; i >= 1; i--){
    	cout << a[i];
    }
    cout << '\n';
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