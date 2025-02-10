

template <const int mod>
class ModInt {
private:
	int x;
	ModInt pow(long long n) const {
		ModInt res(1), mul(x);
		while(n) {
			if(n & 1) res *= mul;
			mul *= mul;
			n >>= 1;
		}
		return res;
	}
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0;
		while(b) {
			int t = a / b;
			a -= t * b;
			std::swap(a, b);
			u -= t * v;
			std::swap(u, v);
		}
		if(u < 0) u += mod;
		return u;
	}
public:
	ModInt(int X = 0) : x(X % mod) {}
	ModInt(long long x) : x(static_cast<int>(X % mod)) {}
	int val() { return x; }
	ModInt operator+ (const ModInt &a) const {
		int x0 = x + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	ModInt operator- (const ModInt &a) const {
		int x0 = x - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}
	ModInt operator* (const ModInt &a) const {
		return ModInt(1LL * x * a.x % mod);
	}
	ModInt operator/ (const ModInt &a) const {
		return *this * a.inv();
	}
	bool operator== (const ModInt &a) const {
		return x == a.x;
	}
	bool operator!= (const ModInt &a) const {
		return x != a.x;
	}
	ModInt &operator+= (const ModInt &a) {
		x += a.x;
		if(x >= mod) x -= mod;
		return *this;
	}
	ModInt &operator-= (const ModInt &a) {
		x -= a.x;
		if(x < 0) x += mod;
		return *this;
	}
	ModInt &operator*= (const ModInt &a) {
		x = 1LL * x * a.x % mod;
		return *this;
	}
	ModInt &operator /=(const ModInt &a) {
		*this = *this / a;
		return *this;
	}
	
};