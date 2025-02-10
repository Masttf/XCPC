#include<iostream>
#include<cstring>
#include<vector>
#include<array>
using namespace std;
using LL = long long;
template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
    bool operator == (const ModInt &a) const { return x == a.x; };
    bool operator != (const ModInt &a) const { return x != a.x; };
    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator /= (const ModInt &a) { *this = *this / a; }
    friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
    friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
    friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}

    ModInt pow(LL n) const {
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
using mint = ModInt<998244353>;

const int maxn = 1e5 + 5, S = 125;
mint pows[maxn][S], invs[maxn][S];

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    for(int i = 1; i < maxn; i++){
        pows[i][0] = 1;
        for(int j = 1; j < S; j++){
            pows[i][j] = pows[i][j - 1] * i;
        }
        invs[i][S - 1] = pows[i][S - 1].inv();
        for(int j = S - 2; j >= 0; j--)
            invs[i][j] = invs[i][j + 1] * i;
    }

    int T;
    cin >> T;
    while(T--){
        LL n, m;
        cin >> n >> m;
        mint cnt[S] = {0};
        cnt[1] = n;

        auto get_size = [&](LL l){
            array<mint, 61> cnt{};
            if (l > n) return cnt;
            cnt[0] = 1;
            LL pow2 = 2;
            if (l == n) return cnt;
            for(int i = 1; ;i++, pow2 *= 2){
                l *= 2;
                if (l > n) break;
                LL r = min(l + pow2 - 1, n);
                cnt[i] = mint(r - l + 1);
            }
            return cnt;
        };

        for(int i = 0; ; i++){
            if ((1LL << (i + 1)) > n) break;
            LL l = 1LL << i, r = (1LL << (i + 1));
            auto sz = get_size(l);
            while(l < r){
                LL mid = (l + r) / 2;
                if (get_size(mid) != sz) r = mid;
                else l = mid + 1;
            }

            auto solve = [&](LL x, mint c){
                auto c1 = get_size(x);
                auto c2 = get_size(2 * x);
                auto c3 = get_size(2 * x + 1);
                for(int i = 1; i <= 60; i++) cnt[i + 1] += c1[i] * c;
                for(int i = 0; i <= 60; i++){
                    for(int j = 0; j <= 60; j++){
                        cnt[i + j + 3] += c2[i] * c3[j] * c;
                    }
                }
            };

            solve(1LL << i, r - (1LL << i));
            if (r < (1LL << (i + 1))) solve(r, 1);
            if (r + 1 < (1LL << (i + 1))) solve(r + 1, (1LL << (i + 1)) - r - 1);
        }

        mint ans = 0;
        for(int i = 1; i < S; i++){
            mint sum = mint(m).pow(n);
            for(int j = 1; j <= m; j++){
                ans += j * cnt[i] * (pows[j][i] - pows[j - 1][i]) * sum * invs[m][i];
            }
        }
        cout << ans << '\n';
        //for(int i=1;i<=8;i++)cout<<cnt[i]<<' ';

    }

}