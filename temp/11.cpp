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
constexpr int mod = 998244353;
using mint = ModInt<mod>;
template <class T, const int M>
struct Matrix{
    T m[M][M];
    int row, col;
    Matrix(){
        row = 0;
        col = 0;
    }
    Matrix(int n){ //单位矩阵
        row = col = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)m[i][j] = 1;
                else m[i][j] = 0;
            }
        }
    }
    Matrix(int r, int c){
        row = r;
        col = c;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                m[i][j] = 0;
            }
        }
    }
    Matrix(vector<vector<T>> a){
        row = a.size();
        col = a[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                m[i][j] = a[i][j];
            }
        }
    }
    Matrix operator * (const Matrix &y) const {
        Matrix res(row, y.col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < y.col; j++){
                for(int k = 0; k < col; k++){
                    res.m[i][j] += m[i][k] * y.m[k][j];
                }
            }
        }
        return res;
    }
    Matrix qmi (long long b){
        Matrix res(row);
        Matrix a = *this;
        while(b){
            if(b & 1) res = res * a;
            b >>= 1;
            a = a * a;
        }
        return res;
    }
    friend ostream &operator<<(ostream &os, const Matrix &a) {
        for(int i = 0; i < a.row; i++){
            for(int j = 0; j < a.col; j++){
                os << a.m[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }
};
using matrix = Matrix<mint, 32>;
void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(m + 1);
    for(int i = 1; i <= m; i++){
    	cin >> a[i];
    }
    if(n <= 6){
    	int ans = 0;
    	int limit = 1 << n;
    	for(int i = 0; i < limit; i++){
    		string t = "";
    		for(int j = n - 1; j >= 0; j--){
    			if(i >> j & 1){
    				t += 'b';
    			}else{
    				t += 'a';
    			}
    		}
    		int ok = 1;
    		for(int j = 1; j <= m; j++){
    			if(t.find(a[j]) != -1)ok = 0;
    		}
    		if(ok){
    			ans++;
    		}
    	}
    	cout << ans << '\n';
    }else{
    	matrix dp(1, 32);
    	matrix b(32, 32);
    	for(int i = 0; i < 32; i++){
    		string t = "";
    		for(int j = 4; j >= 0; j--){
    			if(i >> j & 1){
    				t += 'b';
    			}else{
    				t += 'a';
    			}
    		}
    		int ok = 1;
    		for(int j = 1; j <= m; j++){
    			if(t.find(a[j]) != -1)ok = 0;
    		}
    		if(ok){
    			dp.m[0][i] = 1;
    		}
    	}
    	for(int i = 0; i < 64; i++){
    		string t = "";
    		for(int j = 5; j >= 0; j--){
    			if(i >> j & 1){
    				t += 'b';
    			}else{
    				t += 'a';
    			}
    		}
    		int ok = 1;
    		for(int j = 1; j <= m; j++){
    			if(t.find(a[j]) != -1)ok = 0;
    		}
    		if(ok){
    			int u = i >> 1;
    			int v = i & 31;
    			b.m[u][v] = 1;
    		}
    	}
    	dp = dp * b.qmi(n - 5);
    	mint ans = 0;
    	for(int i = 0; i < 32; i++){
    		ans += dp.m[0][i];
    	}
    	cout << ans << '\n';
    }
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