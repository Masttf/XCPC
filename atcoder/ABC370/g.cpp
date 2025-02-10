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
    ModInt(int x = 0) : x(x % mod) {}
    //ModInt(long long x) : x(int(x % mod)) {} 
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
constexpr int mod = 998244353;
using mint = ModInt<mod>;
constexpr int maxn = 1e6 + 5;
vector<int>prim;
vector<mint>sump(1);
vector<int>vis(maxn);
mint f[maxn], inv[maxn];
void init(int n){
    vis[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!vis[i]){
            prim.push_back(i);
            sump.push_back(sump.back() + (i % 3 == 2 ? 0 : 1));
        }
        for(int j = 0; prim[j] * i <= n; j++){
            vis[i * prim[j]] = 1;
            if(i % prim[j] == 0)break;
        }
    }
    f[0] = inv[0] = 1;
    for(int i = 1; i < maxn; i++){
        f[i] = f[i - 1] * i;
    }
    inv[maxn - 1] = f[maxn - 1].inv();
    for(int i = maxn - 1; i >= 1; i--){
        inv[i - 1] = inv[i] * i;
    }
}
mint C(int m, int n){
    if(m < 0 || m > n)return 0;
    return f[n] * inv[m] * inv[n - m];
}
void solve(){
    int n, m; cin >> n >> m;
    int B = sqrt(n);
    while(B * B < n)B++;
    while(B * B > n)B--;
    init(B);
    int sz = prim.size();
    vector<int> id1(B + 1), id2(B + 1), w(2 * B + 1);
    vector<mint> g(2 * B + 1), h(2 * B + 1);
    vector<array<mint, 3>> ff(2 * B + 1), fp(sz + 1);
    int tot = 0;
    for(int i = 0; i < sz; i++){
        fp[i + 1] = fp[i];
        fp[i + 1][prim[i] % 3] += 1;
    }
    for(int i = 1, j; i <= n; i = j + 1){
        j = n / (n / i);
        w[++tot] = n / i;
        for(int k = 0; k < 3; k++){
            ff[tot][k] = mint(w[tot] / 3) + ((k + 2) % 3 < w[tot] % 3);
        }
        ff[tot][1] -= 1;
        if(w[tot] % 3 >= 1)h[tot] += m;
        if(w[tot] <= B)id1[w[tot]] = tot;
        else id2[j] = tot;
    }
    for(int i = 0; i < sz; i++){
        for(int j = 1; j <= tot; j++){
            if(prim[i] * prim[i] > w[j])break;
            int k = w[j] / prim[i];
            if(k <= B) k = id1[k];
            else k = id2[n / k];
            for(int t = 0; t < 3; t++){
                ff[j][prim[i] * t % 3] -= ff[k][t] - fp[i][t];
            }
        }
    }
    for(int i = 1; i <= tot; i++){
        g[i] = (ff[i][0] + ff[i][1] + ff[i][2]) * m;
        h[i] = (ff[i][0] + ff[i][1]) * m;
    }
    //2~x最小质因子大于等于prim[y]的和
    auto Min_25 = [&](auto self, int x, int y) -> mint{
        if(x <= 1)return 0;
        int k = x;
        if(k <= B) k = id1[k];
        else k = id2[n / k];
        
        mint res = g[k] - mint(y * m);
        for(int i = y; i < sz; i++){
            if(prim[i] * prim[i] > x)break;
            int t1 = prim[i], t2 = prim[i] * prim[i];
            for(int e = 1; t2 <= x; e++){
                res += C(m - 1, e + m - 1) * self(self, x / t1, i + 1) + C(m - 1, e + m);
                t1 = t2;
                t2 *= prim[i];
            }
        }
        return res;
    };
    auto Min_252 = [&](auto self, int x, int y) -> mint{
        if(x <= 1)return 0;
        int k = x;
        if(k <= B) k = id1[k];
        else k = id2[n / k];
        mint res = h[k] - mint(sump[y] * m);
        for(int i = y; i < sz; i++){
            if(prim[i] * prim[i] > x)break;
            int t1 = prim[i], t2 = prim[i] * prim[i];
            int sum = 1;
            for(int e = 1; t2 <= x; e++){
                sum += t1;
                if(sum % 3 != 0)res += C(m - 1, e + m - 1) * self(self, x / t1, i + 1);
                if((sum + t2) % 3 != 0) res += C(m - 1, e + m);
                t1 = t2;
                t2 *= prim[i];
            }
        }
        return res;
    };
    mint d1 = Min_25(Min_25, n, 0);
    mint d2 = Min_252(Min_252, n, 0);
    //dbg(d1, d2);
    mint ans = d1 - d2;
    cout << ans << '\n';
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