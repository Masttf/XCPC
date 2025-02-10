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
template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x < 0 ? x % mod + mod : x % mod) {}
    // ModInt(long long x) : x(int(x < 0 ? x % mod + mod : x % mod)) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { 
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod); 
    }
    ModInt operator - (const ModInt &a) const {
        int x0 = x - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    ModInt operator * (const ModInt &a) const {
        return ModInt(1LL * x * a.x % mod);
    }
    ModInt operator / (const ModInt &a) const {
        return *this * a.inv();
    }
    bool operator == (const ModInt &a) const {
        return x == a.x;
    }
    bool operator != (const ModInt &a) const {
        return x != a.x;
    }
    void operator += (const ModInt &a) {
        x += a.x;
        if (x >= mod) x -= mod;
    }
    void operator -= (const ModInt &a) {
        x -= a.x;
        if (x < 0) x += mod;
    }
    void operator *= (const ModInt &a) {
        x = 1LL * x * a.x % mod;
    }            
    void operator /= (const ModInt &a) {
        *this = *this / a;
    }
    friend ModInt operator + (int y, const ModInt &a){
        int x0 = y + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    friend ModInt operator - (int y, const ModInt &a){
        int x0 = y - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }            
    friend ModInt operator * (int y, const ModInt &a){
        return ModInt(1LL * y * a.x % mod);
    }
    friend ModInt operator / (int y, const ModInt &a){
        return ModInt(y) / a;
    }
    friend ostream &operator<<(ostream &os, const ModInt &a) {
        return os << a.x;
    }
    friend istream &operator>>(istream &is, ModInt &t){
        return is >> t.x;
    }                        
                
    ModInt pow(long long n) const {
    ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
                
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
                
};
constexpr int mod = 1e9 + 7;
using mint = ModInt<mod>;
int statu[100];
map<int, int> m;
mint dp[2][100][100], p[10];
vector<int> g[100];
vector<array<int, 3>> to[2048];
int tot = 0;
void init(){
    for(int i = 0; i < (1 << 9); i++){
        int cnt = 0;
        for(int j = 0; j < 9; j++){
            if(i >> j & 1){
                cnt++;
            }
        }
        if(cnt == 3){
            tot++;
            int x = i * 2;
            statu[tot] = x;
            m[x] = tot;
        }
    }
    for(int i = 1; i <= tot; i++){
        for(int j = 1; j <= tot; j++){
            if(statu[i] & statu[j])continue;
            g[i].push_back(j);
        }
    }
    p[0] = 1;
    for(int i = 1; i <= 3; i++){
        p[i] = p[i - 1] * i;
    }
    int mx = 0;
    for(int i = 1; i <= 9; i++){
        mx |= (1 << i);
    }
    for(int i = 0; i < (1 << 9); i++){
        int cnt = 0;
        for(int j = 0; j < 9; j++){
            if(i >> j & 1){
                cnt++;
            }
        }
        if(cnt <= 3){
            int x = i * 2;
            for(int j = 1; j <= tot; j++){
                if(statu[j] & x)continue;
                for(auto v : g[j]){
                    if(statu[v] & x)continue;
                    int u = mx - statu[j] - statu[v];
                    u = m[u];
                    to[x].push_back({j, v, u});
                }
            }
        }
    }
    return ;
}
void solve(){
    int n; cin >> n;
    vector<string> a(4);
    for(int i = 1; i <= 3; i++){
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    vector<int> c_c(10);
    for(int i = 1; i <= n; i++){
        c_c.assign(10, 0);
        for(int j = 1; j <= 3; j++){
            if(a[j][i] == '?')continue;
            c_c[a[j][i] - '0']++;
            if(c_c[a[j][i] - '0'] >= 2){
                cout << 0 << '\n';
                return ;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <= tot; j++){
            for(int k = 0; k <= tot; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    auto get = [&](int i) -> pair<int, int>{
        int cnt = 0;
        int val = 0;
        for(int j = 1; j <= 3; j++){
            if(a[j][i] == '?')cnt++;
            else{
                int x = a[j][i] - '0';
                val |= (1 << x);
            }
        }
        return {cnt, val};
    };
    auto [c1, v1] = get(1);
    auto [c2, v2] = get(2);
    for(int i = 1; i <= tot; i++){
        int x = statu[i];
        if((v1 & x) != v1)continue;
        for(auto j : g[i]){
            int y = statu[j];
            if((v2 & y) != v2)continue;
            dp[0][i][j] += p[c1] * p[c2];
        }
    }
    for(int i = 3, now = 1; i <= n; i++, now ^= 1){
        auto [cnt, val] = get(i);
        for(int j = 1; j <= tot; j++){
            for(auto v : g[j]){
                dp[now][j][v] = 0;
            }
        }
        for(auto [j, v, u] : to[val]){
            dp[now][v][u] += dp[now ^ 1][j][v] * p[cnt];
        }
    }
    mint ans = 0;
    int now = n % 2;
    for(int i = 1; i <= tot; i++){
        for(auto v : g[i]){
            ans += dp[now][i][v];
        }
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    init();
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
C(3, 9)
3 * 4 * 7
12 * 7
84
*/