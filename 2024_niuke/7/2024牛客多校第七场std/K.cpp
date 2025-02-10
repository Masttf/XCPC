#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1000005;
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

}  // namespace chino
using Int = chino::ModInt<MOD>;
class SequencesAutomata
{
   private:
    vector<long long> _dp;
    vector<array<int, 26>> _next;
    int state;

   public:
    explicit SequencesAutomata(const char* s) : state(0)
    {
        int l = (int)strlen(s);
        array<int, 26> last{};
        fill(last.begin(), last.end(), -1);
        for (int i = l - 1; i >= 0; --i)
        {
            _next.emplace_back(last);
            last[s[i] - 'a'] = i + 1;
        }
        _next.emplace_back(last);
        reverse(_next.begin(), _next.end());
        _dp = vector<long long>(l + 1, -1);
    }

    void init()
    {
        state = 0;
    }

    bool next(const char c)
    {
        if (_next[state][c - 'a'] != -1)
        {
            state = _next[state][c - 'a'];
            return true;
        }
        return false;
    }

    int operator()() const
    {
        return state;
    }

    long long operator()(int x)
    {
        if (_dp[x] != -1)
        {
            return _dp[x];
        }
        _dp[x] = 1;
        for (auto& i : _next[x])
        {
            if (i == -1)
                continue;
            _dp[x] += this->operator()(i);
            if (_dp[x] >= MOD)
            {
                _dp[x] -= MOD;
            }
        }
        return _dp[x];
    }
};
namespace chino
{
class manacherWrapper
{
   private:
    size_t l_;
    std::vector<char> s_;

   public:
    std::vector<int> p;
    std::vector<int> b;
    std::vector<int> s;

    explicit manacherWrapper(const char* str)
    {
        auto l = strlen(str);
        //rebuild
        l_ = l;
        s_.resize(((l_ + 1) << 1) | 1);
        p.resize(((l_ + 1) << 1) | 1);
        b.resize(l_);
        s.resize(l_ + 1);

        s_[0] = '$', s_[1] = '#';

        for (int i = 0; i < l_; ++i)
            s_[(i + 1) << 1] = str[i], s_[((i + 1) << 1) | 1] = '#';
        l_ = (l_ + 1) << 1;
        //calc p
        int mx = 0, id;
        for (int i = 0; i < l_; ++i)
        {
            if (mx > i)
                p[i] = std::min(p[(id << 1) - i], mx - i);
            else
                p[i] = 1;
            for (; s_[i - p[i]] == s_[i + p[i]]; p[i]++)
                ;
            if (p[i] + i > mx)
            {
                mx = p[i] + i;
                id = i;
            }
        }
        //calc b and s
        for (int i = 0; i < l; ++i)
        {
            auto lp = get(i);
            b[i - (lp >> 1)] = std::max(b[i - (lp >> 1)], lp);
            s[i - (lp >> 1)]++, s[i + 1]--;
            if (i + 1 >= l)
                break;
            lp = get(i, i + 1);
            if (lp > 0)
            {
                b[i + 1 - (lp >> 1)] = std::max(b[i + 1 - (lp >> 1)], lp);
                s[i + 1 - (lp >> 1)]++, s[i + 1]--;
            }
        }
        for (int i = 1; i < l; ++i)
        {
            b[i] = std::max(b[i], b[i - 1] - 2);
            s[i] += s[i - 1];
        }
    }

    int get(size_t pos)
    {
        return (int)p[(pos + 1) << 1] - 1;
    }

    int get(size_t posl, size_t posr)
    {
        return (int)p[((posl + 1) << 1) | 1] - 1;
    }

    int longestBegin(size_t begin)
    {
        return b[begin];
    }

    int totalBegin(size_t begin)
    {
        return s[begin];
    }

    bool isPalindrome(size_t l, size_t r)
    {
        if (l > r)
            std::swap(l, r);
        auto mid = (l + r) >> 1;
        auto len = (r - l + 1);
        return len & 1 ? get(mid) >= len : get(mid, mid + 1) >= len;
    }
};
}  // namespace chino
char s[MAXN], t[MAXN];
int main()
{
    int n, m;
    Int ans;
    scanf("%d %d", &n, &m);
    scanf("%s %s", s, t);
    if(m>n){
        printf("0\n");
        return 0;
    }
    SequencesAutomata S(s);
    reverse(s, s + n);
    SequencesAutomata IS(s);
    reverse(s, s + n);
    chino::manacherWrapper man(t);
    for (int i = 0; i < m; ++i)
    {
        S.next(t[i]);
        IS.next(t[i]);
    }
    if (S() != -1 && IS() != -1)
    {
        //cout << S() << " " << IS() << endl;
        if (S() == n - IS())
        {
            ans = 1;
        }
        else if (S() < n - IS())
        {
            string temp;
            for (int i = S(); i < n - IS(); ++i)
            {
                temp += s[i];
            }
            SequencesAutomata t(temp.c_str());
            ans = t(0);
        }
        //cout << ans.get() << endl;
    }
    //cout << ans.get() << endl;
    if (S() != -1)
    {
        IS.init();
        for (int i = 0; i < m && IS() != -1; ++i)
        {
            if (man.isPalindrome(i, m - 1) && S() <= n - IS())
            {
                ans = ans + 1;
            }
            IS.next(t[i]);
        }
    }
    printf("%d\n", ans.get());
    return 0;
}