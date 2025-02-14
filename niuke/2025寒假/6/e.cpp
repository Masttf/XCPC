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
void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n + 1);
    vector<pair<int, int>> tmp;
    vector<int> stk1, stk2;
    multiset<int> pos;
    pos.insert(0);
    
    for(int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++){
        while (!stk1.empty() && a[stk1.back()] >= a[i])
            pos.erase(pos.find(stk1.back())), stk1.pop_back();
        while (!stk2.empty() && a[stk2.back()] <= a[i])
            pos.erase(pos.find(stk2.back())), stk2.pop_back();
        stk1.push_back(i);
        stk2.push_back(i);
        pos.insert(i);
        pos.insert(i);
        int mi = 1e9, mx = 0;
        for (auto it = next(pos.rbegin()); it != pos.rend(); it++){
            int pre = *prev(it);
            int cur = *it;
            mi = min(mi, a[pre]), mx = max(mx, a[pre]);
            int val = 1ll * mi * mx;
            tmp.push_back({val, pre - cur});
        }
    }
    sort(tmp.begin(), tmp.end());
    vector<pair<int, int>> b;
    for (int i = 0; i < tmp.size();){
        int j = i;
        int sum = 0;
        while (j < tmp.size() and tmp[i].first == tmp[j].first){
            sum += tmp[j].second;
            j++;
        }
        b.push_back({tmp[i].first, sum});
        i = j;
    }
    for(int i = (int)b.size() - 2; i >= 0; i--)b[i].second += b[i + 1].second;
    while(q--){
        int k;
        cin >> k;
        auto it = lower_bound(b.begin(), b.end(), pair<int, int>{k, 0});
        if(it == b.end()) cout << 0 << '\n';
        else cout << it->second << '\n';
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
/*
mx * mi
均匀随机生成
也就是说每个数个数应该很平均
还给3s
n^2做法
怎么在随机情况下变成nlog？
算法复杂度应该和随机有关
点对该怎么做
枚举l log算r？
或者说如何枚举 mx 和mi
每个数出现概率大概是 n / m
如果 m 很小咋做
m  < sqrt n

*/