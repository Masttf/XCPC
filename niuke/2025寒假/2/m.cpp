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
mint f[10], inv[10];
void init(){
    f[0] = inv[0] = 1;
    for(int i = 1; i < 10; i++){
        f[i] = f[i - 1] * i;
    }
    inv[9] = f[9].inv();
    for(int i = 9; i >= 1; i--){
        inv[i - 1] = inv[i] * i;
    }
}
mint C(int n, int m){
    if(n < 0 || m > n)return 0;
    return f[n] * inv[m] * inv[n - m];
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
    mint ans = 1;
    vector<set<int>> res(3);
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= 3; j++){
            if(a[j][i] == '?'){
                sum++;
                ans = ans * sum;
            }else{
                res[i % 3].insert(a[j][i] - '0');
            }
        }
    }
    int mx = 0;
    set<int> used;
    int tot = 0;
    for(int i = 0; i <= 2; i++){
        tot += res[i].size();
        mx = max((int)res[i].size(), mx);
        for(auto it : res[i]) used.insert(it);
    }
    if(mx > 3 || tot != used.size()){
        cout << 0 << '\n';
        return ;
    }
    tot = 9 - tot;
    for(int i = 0; i <= 2; i++){
        ans = ans * C(tot, 3 - res[i].size());
        tot -= 3 - res[i].size();
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