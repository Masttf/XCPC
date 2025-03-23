#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int mxa = *max_element(a.begin(), a.end());
    int mxb = *max_element(b.begin(), b.end());
    set<int> a_set(a.begin(), a.end());

    // 预处理检查
    bool valid = true;
    for (int x : b) {
        if (x > mxa && !a_set.count(x)) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        cout << -1 << "\n";
        return;
    }

    // 检查排列情况
    vector<int> a_sorted(a), b_sorted(b);
    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());
    if (a_sorted == b_sorted) {
        cout << max(mxa, mxb) + 1 << "\n";
        return;
    }

    // 生成候选k
    set<int> candidates;
    set<int> b_vals(b.begin(), b.end());
    
    // 因数生成函数
    auto get_factors = [](int c) {
        vector<int> factors;
        if (c == 0) return factors;
        for (int i = 1; i * i <= c; ++i) {
            if (c % i == 0) {
                if (i <= 1e9) factors.push_back(i);
                int j = c / i;
                if ( i * i != c && j <= 1e9) factors.push_back(j);
            }
        }
        return factors;
    };

    // 只处理a中的最大值元素
    for (int x : b_vals) {
        if (x > mxa) continue;
        if (x == mxa) {
            candidates.insert(mxb + 1);
        } else {
            int c = mxa - x;
            auto factors = get_factors(c);
            for (int d : factors) {
                if (d > mxb && d > x) candidates.insert(d);
            }
        }
    }
    candidates.insert(mxa + 1);

    // 准备验证数据
    map<int, int> b_count;
    set<int> b_set(b.begin(), b.end());
    for (int x : b) b_count[x]++;

    // 验证候选k（降序检查）
    int ans = -1;
    vector<int> pk(candidates.rbegin(), candidates.rend());
    for (int k : pk) {
        if (k <= mxb) continue;
        map<int, int> tmp;
        bool flag = true;
        for (int x : a) {
            int mod = x % k;
            if (!b_set.count(mod)) {
                flag = false;
                break;
            }
            tmp[mod]++;
            if (tmp[mod] > b_count[mod]) {
                flag = false;
                break;
            }
        }
        if (flag && tmp == b_count) {
            ans = k;
            break;
        }
    }

    // 检查大范围k值
    if (ans == -1) {
        int start = max(mxb + 1, mxa + 1);
        for (int k = start; k <= start + 1000; ++k) {
            map<int, int> tmp;
            bool flag = true;
            for (int x : a) {
                int mod = x % k;
                if (!b_set.count(mod)) {
                    flag = false;
                    break;
                }
                tmp[mod]++;
                if (tmp[mod] > b_count[mod]) {
                    flag = false;
                    break;
                }
            }
            if (flag && tmp == b_count) {
                ans = k;
                break;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}