#define GKD std::cin.tie(nullptr)->std::ios::sync_with_stdio(false)
#define clr(a, b) memset(a, b, sizeof(a))
#define cpy(a, b) memcpy(a, b, sizeof(a))
// #define _DEBUG
// #define PRIME

#include <iostream>
#include <vector>

#ifdef _DEBUG

#define dbg(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)

void err() { std::cout << std::endl; }

template <class T, class... Ts>
void err(T arg, Ts&... args) {
    std::cout << arg << ' ';
    err(args...);
}

#else

#define dbg(x...) 114514;

#endif

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int INF = 0x3f3f3f3f;
ll mod = 0;

inline ll qpow(ll _a, ll _n, ll _mod = mod) {
    ll ans = 1;
    while (_n) {
        if (_n & 1) ans *= _a;
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

namespace prime {
const int N = 1e7 + 100;
vector<int> minp(N);
vector<int> primes;
bitset<N> st;

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) minp[i] = i, primes.emplace_back(i);
        for (int j = 0; primes[j] * i <= n; j++) {
            int t = primes[j] * i;
            st[t] = true;
            minp[t] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}
}  // namespace prime

#endif


template<const int T, const int bit>
struct Tree{
    struct node {
        int next[T] = {};
    };
    int tot = 1;
    vector<node> tr;
    vector<int> mxIndex;
    Tree() {
        tot = 1;
        tr.resize(1);
        mxIndex.resize(1);
    }
    Tree(int n) {
        tot = 1;
        tr.assign((n + 1) * bit, node());
        mxIndex.assign((n + 1) * bit, -INF);
    }
    void insert(int x, int val) {
        int p = 1;
        for (int i = 30; i >= 0; i--) {
            int d = (x >> i) & 1;
            if(tr[p].next[d] == 0){
                tr[p].next[d] = ++tot;
            }
            p = tr[p].next[d];
            mxIndex[p] = max(mxIndex[p], val);
        }
    }
    int query(int x,  int k) {
        int ans = -INF;
        int p = 1;
        for (int i = 30; i >= 0; i--) {
            int bitx = (x >> i) & 1;
            int bitk = (k >> i) & 1;
            if (bitk == 0) {
                if (tr[p].next[!bitx] != 0) {
                    ans = max(ans, mxIndex[tr[p].next[!bitx]]);
                }
                p = tr[p].next[bitx];
            } else {
                p = tr[p].next[!bitx];
            }
        }
        ans = max(ans, mxIndex[p]);
        return ans;
    }
};

inline void init() { /*Init Here*/ }

void idol_produce(int testCase) {
    /*Code Here*/
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = INF;
    Tree<2, 32> tr(n);
    for(int i = 1; i <= n; i++){
        tr.insert(a[i], i);
        int t = tr.query(a[i], k);

        ans = min(ans, i - t + 1);
    }
    if(ans > n) ans = -1;
    cout << ans << '\n';
    return ;
}

signed main() {
    GKD;
    init();
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        idol_produce(i);
    }
    return 0;
}
