#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int x, int y) {
    if (x == y) return -1; // 相同无法消除进位
    int conflict = x & y;
    if (conflict == 0) return 0;
    
    // 寻找最高冲突位
    int highest_bit = 0;
    for (int i = 0; i <= 60; ++i)
        if ((conflict >> i) & 1) 
            highest_bit = i;
    
    // 构造掩码: 将[0..highest_bit]位清零
    int mask = (1LL << (highest_bit + 1));
    int k = mask - (x & (mask - 1));
    
    // 验证新值是否有效
    int new_x = x + k;
    int new_y = y + k;
    if ((new_x & new_y) == 0 && k <= 1e18)
        return k;
    
    // 特殊处理高位进位冲突
    if ((new_x & mask) && (new_y & mask)) {
        int max_low = 0;
        for (int i = 0; i <= highest_bit; ++i) {
            if ((x >> i) & 1) max_low = max(max_low, (1LL << i) - (x & ((1LL << i) - 1)));
            if ((y >> i) & 1) max_low = max(max_low, (1LL << i) - (y & ((1LL << i) - 1)));
        }
        k -= max_low;
        new_x = x + k;
        new_y = y + k;
        return (new_x & new_y) == 0 ? k : -1;
    }
    
    return -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << '\n';
    }
    return 0;
}