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

const int maxn = 1e5 + 5;
int vis[maxn];
pair<int,int> ans[maxn];
vector<int>num;

bool cmp(pair<int,int>a,pair<int,int>b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

void solve(){
    int n,m,q;cin >> n >> m >> q;
    for (int i = 1;i <= m;i++) {
        vis[i] = ans[i].first = 0;
        ans[i].second = i; 
    }
    num.clear();
    int stage = -1,val = m;
    for (int i = 1;i <= q;i++) {
        int op;cin >> op;
        if (op == 1) {
            int x;cin >> x;
            stage = x;
            for (auto i : num) vis[i] = 0;
            num.clear();
            val = m;
        }
        else if (op == 2) {
            int id,x;cin >> id >> x;
            if (vis[id]) continue;
            if (stage != x) continue;
            ans[id].first += val;
            val--;
            num.push_back(id);
            vis[id] = 1;
        }
        else {
            int id,x;cin >> id >> x;
            if (stage != x) continue;
            if (vis[id]) continue;
            vis[id] = 1;
            num.push_back(id);
        }
    }
    sort(ans + 1,ans + 1 + m,cmp);
    for (int i = 1;i <= m;i++) {
        cout << ans[i].second << ' ' << ans[i].first << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;  cin >> t;
    while(t--)solve();
    return 0;
}