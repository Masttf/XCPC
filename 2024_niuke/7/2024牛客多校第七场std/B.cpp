#include <bits/stdc++.h>

using namespace std;
namespace chino
{
template <int mod>
class ModInt
{
   private:
    const static int MD = mod;
    int x;

   public:
    ModInt(long long x = 0) : x(x % MD) {}

    int get()
    {
        return x;
    }

    ModInt operator+(const ModInt& that) const
    {
        int x0 = x + that.x;
        return ModInt(x0 < MD ? x0 : x0 - MD);
    }

    ModInt operator-(const ModInt& that) const
    {
        int x0 = x - that.x;
        return ModInt(x0 < MD ? x0 + MD : x0);
    }

    ModInt operator*(const ModInt& that) const
    {
        return ModInt((long long)x * that.x % MD);
    }

    ModInt operator/(const ModInt& that) const
    {
        return *this * that.inverse();
    }

    ModInt operator+=(const ModInt& that)
    {
        x += that.x;
        if (x >= MD)
            x -= MD;
        return x;
    }

    ModInt operator-=(const ModInt& that)
    {
        x -= that.x;
        if (x < 0)
            x += MD;
        return x;
    }

    ModInt operator*=(const ModInt& that)
    {
        return x = (long long)x * that.x % MD;
    }

    ModInt operator/=(const ModInt& that)
    {
        return *this = *this / that;
    }

    ModInt inverse() const
    {
        int a = x, b = MD, u = 1, v = 0;
        while (b)
        {
            int t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        if (u < 0)
            u += MD;
        return u;
    }
};

template <int mod>
class Combination
{
   private:
    using Mint = ModInt<mod>;
    std::vector<Mint> fact, inv_fact;

   public:
    Combination(int n) : fact(n + 1), inv_fact(n + 1)
    {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            fact[i] = fact[i - 1] * i;
        }
        inv_fact[n] = fact[n].inverse();
        for (int i = n - 1; i >= 0; --i)
        {
            inv_fact[i] = inv_fact[i + 1] * (i + 1);
        }
    }

    Mint operator()(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }

    Mint operator()(int n)
    {
        return fact[n];
    }
};

}  // namespace chino
const int N = 400005;
const int MOD = 1e9 + 7;
using Int = chino::ModInt<MOD>;
vector<int> five;

int main()
{
    int T, n, m, k;
    chino::Combination<MOD> C(N);
    for (int i = 1;; ++i)
    {
        if ((3 * i * i - i) / 2 >= N)
            break;
        five.push_back((3 * i * i - i) / 2);
        if ((3 * i * i + i) / 2 >= N)
            break;
        five.push_back((3 * i * i + i) / 2);
    }
    auto solve = [&](int x, int y) -> Int
    {
        Int ans = C(x + y, y);
        if (y > x + 1)
        {
            ans += C(x + y + 1 - x - 2, y - x - 2);
        }
        for (auto i = 0; i < five.size() && five[i] <= y; ++i)
        {
            Int val = ((i >> 1) & 1) ? 1 : MOD - 1;
            ans += val * C(x + y - five[i], y - five[i]);
            if (y - five[i] > x + 1)
            {
                ans +=
                    val * C(x + y - five[i] + 1 - x - 2, y - five[i] - x - 2);
            }
        }
        return ans;
    };
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &n, &m, &k);
        int query = 1LL * n * m / k;

        Int ans = solve(n + 1, query);
        if (query > n + 1)
        {
            //ans += solve(n + 1, query - n - 2);
        }
        printf("%d\n",(Int(1) - ans * C(n + 1).inverse()).get());
    }
}