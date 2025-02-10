#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;

constexpr int N = 3e5 + 5, mod = 998244353;
constexpr double eps = 1e-8;
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#define fi first
#define se second
#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int ksm(int a, int b){
    a %= mod;
    int res = 1;
    while(b){
        if(b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int n, m;
int a[N];
int color[N];
vector<int>g[N];
bool dfs(int u, int c)
{
    color[u] = c;
    for(auto v : g[u]){
        if(!color[v]){
            if(!dfs(v, 3 - c)) return false;
        }
        else if(color[v] == c) return false;
    }
    return true;
}

void Sakuya()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++ i){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(v);
    }

    bool flag = true;

    for(int i = 1; i <= n; i ++){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }

    if(!flag){
        cout << "Alice" << endl;
        int u, v;
        for(int i = 1; i <= n; ++ i){
            cout << 1 << " " << 2 << endl;
            cin >> u >> v;
        }
    }else {
        cout << "Bob" << endl;
        stack<int>v1, v2;
        for(int i = 1; i <= n; ++ i){
            if(color[i] == 1)v1.emplace(i);
            else v2.emplace(i);
        }

        for(int i = 1; i <= n; ++ i){
            int u, v;
            cin >> u >> v;
            if((u == 2 || v == 2) && v2.size()){
                cout << v2.top() << " " << 2 << endl;
                v2.pop();
            }else if((u == 1 || v == 1) && v1.size()){
                cout << v1.top() << " " << 1 << endl;
                v1.pop();
            }else {
                if(v2.size()){
                    cout << v2.top() << " " << 3 << endl;
                    v2.pop();
                }else {
                    cout << v1.top() << " " << 3 << endl;
                    v1.pop();
                }
            }
        }
    }
    for(int i = 1; i <= n; ++ i){
        color[i] = 0;
        g[i].clear();
    }
}

signed main()
{
    int T;
    for (cin >> T; T -- ; )
        Sakuya();

}