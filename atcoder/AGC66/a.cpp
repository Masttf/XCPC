#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int N = 1e3 + 5, mod = 998244353;
constexpr double eps = 1e-8;

#define fi first
#define se second
#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int n, k, d1, d2, d;

int g[N][N], G[N][N];

bool check1(){
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            G[i][j] = g[i][j];
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            G[i][j] = G[i][j]-(G[i][j] % d +d)%d;
            if((i+j)%2==0){ //oushu
                if(((G[i][j]/d)%2+2)%2==1){
                    G[i][j]+=d;
                }
            }else {
                if(((G[i][j]/d)%2+2)%2==0)G[i][j]+=d;
            }
            cnt+=abs(g[i][j]-G[i][j]);
        }
    }
    // cout << cnt << "\n";
    // int sum=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<G[i][j]<<' ';
    //         sum+=abs(G[i][j]-g[i][j]);
    //     }
    //     cout<<'\n';
    // }
    return 2*cnt <= n * n * d ;
}

bool check2(){
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            G[i][j] = g[i][j];
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            G[i][j] = G[i][j]-(G[i][j] % d +d)%d; 
            if((i+j)%2==0){
                if(((G[i][j]/d)%2+2)%2==0)G[i][j]+=d;
            }else {
                if(((G[i][j]/d)%2+2)%2==1)G[i][j]+=d;
            }
            cnt+=abs(g[i][j]-G[i][j]);
        }
    }
    // int sum=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<G[i][j]<<' ';
    //         sum+=abs(G[i][j]-g[i][j]);
    //     }
    //     cout<<'\n';
    // }
    

    return 2*cnt <= n * n * d ;
}

void Sakuya()
{
    cin >> n >> d;
    
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            cin >> g[i][j];
        }
    }

    if(check1()){
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                cout << G[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }

    if(check2()){
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                cout << G[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }

    cout << "what can i say?" << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();

}