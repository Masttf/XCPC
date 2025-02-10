
/*
  ______                 _    _  __      ___ _
 |  ____|               | |  (_) \ \    / (_) |
 | |__ _   _ _   _ _   _| | ___   \ \  / / _| | __ _
 |  __| | | | | | | | | | |/ / |   \ \/ / | | |/ _` |
 | |  | |_| | |_| | |_| |   <| |    \  /  | | | (_| |
 |_|   \__,_|\__, |\__,_|_|\_\_|     \/   |_|_|\__,_|
              __/ |
             |___/
*/

#define GKD std::cin.tie(nullptr)->std::ios::sync_with_stdio(false)
#define clr(a, b) memset(a, b, sizeof(a))
#define cpy(a, b) memcpy(a, b, sizeof(a))
//#define LOCAL
//#define PRIME

#include <bits/stdc++.h>



using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
ll mod = 0;

inline ll qpow(ll _a, ll _n, ll _mod = mod) {
    ll ans = 1;
    while (_n) {
        if (_n & 1)
            ans *= _a;
        _n >>= 1;
        _a *= _a;
        if (_mod > 0) {
            ans %= _mod;
            _a %= _mod;
        }
    }
    return ans;
}

#ifdef PRIME

const int N = 1e7 + 100;
vector<int> minp(N);
vector<int> primes;
bitset<N> st;

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            minp[i] = i, primes.emplace_back(i);
        for (int j = 0; primes[j] * i <= n; j++) {
            int t = primes[j] * i;
            st[t] = true;
            minp[t] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
}

#endif

inline void init() {
    /*Init Here*/
    mod = 1e9 + 7;
}

#define int ll
int f[1000005];
vector<int> e[1000005];
bool vis[1000005];
int ans = 0, ans2 = 1;

void solve(int x) {
    while (!vis[x]) {
        vis[x] = 1;
        x = f[x];
    }
    dbg(x);
    vector<int> circle;
    unordered_map<int, bool> inCircle;
    while (!inCircle[x]) {
        inCircle[x] = 1;
        circle.emplace_back(x);
        x = f[x];
    }
    vector<int> mul;
    vector<int> mul2;
    for (auto const &c: circle) {
        if (e[c].size() == 1) continue;
        mul.emplace_back(e[c].size());
        queue<int> q;
        q.push(c);
        int y = 1;
        int sum = 0, son = 0;
        while (!q.empty()) {
            auto p = q.front();
            vis[p] = 1;
            q.pop();
            sum++;
            if (e[p].empty()) {
                son++;
            } else if (p != c) {
                y *= e[p].size();
                y %= mod;
            }
            for (auto const &ed: e[p]) {
                if (!inCircle[ed]) {
                    q.push(ed);
                }
            }
        }
        mul2.emplace_back(y);
        ans += sum - son - 1;
        ans %= mod;
    }
    if (mul.empty()) {
        ans += circle.size() - 1;
        ans2 = (ans2 * circle.size()) % mod;
        return;
    }
    ans = (ans + circle.size()) % mod;
    int tmp = 1;
    for (auto const &i: mul) {
        tmp *= i;
        tmp %= mod;
    }
    tmp -= 1;
    for (auto const &i: mul2) {
        tmp *= i;
        tmp %= mod;
    }
    ans2 *= tmp;
    ans2 %= mod;
}

void idol_produce(int testCase) {
    /*Code Here*/
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[i] = x;
        e[x].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            solve(i);
        }
    }
    int tmp = 1;
    for (int i = 1; i <= n - ans; i++) {
        tmp = tmp * i % mod;
    }
    cout << ans % mod << ' ' << ans2 * tmp % mod << '\n';
}

signed main() {
    GKD;
    init();
    int T = 1;
//    cin >> T;
    for (int i = 1; i <= T; i++) {
        idol_produce(i);
    }
    return 0;
}
