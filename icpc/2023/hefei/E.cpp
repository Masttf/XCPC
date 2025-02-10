#include<bits/stdc++.h>
#define int long long
using namespace std;
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

const int maxn = 1005;
const int MAX = 1e6 + 5;
int c[maxn][maxn];
vector<int>row_color[MAX];
vector<int>col_color[MAX];

void solve(){
    int n,m;cin >> n >> m;
    unordered_map<int,int>mp;
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> c[i][j];
            if (!mp[c[i][j]]) {
                cnt++;
                mp[c[i][j]] = cnt;
                row_color[cnt].push_back(i);
                col_color[cnt].push_back(j);
            }
            else {
                int now = mp[c[i][j]];
                row_color[now].push_back(i);
                col_color[now].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= cnt;i++) {
        sort(row_color[i].begin(), row_color[i].end());
        int len = row_color[i].size();
        int sum = 0,pre = 0;
        for (int j = 0;j < len;j++) {
            //dbg(row_color[i][j],i);
            sum += row_color[i][j];
        }
        for (int j = 0;j < len;j++) {
            sum -= row_color[i][j];
            ans += (sum - row_color[i][j] * (len - j - 1));
            ans += (row_color[i][j] * j - pre);
            pre += row_color[i][j];
        }
        sort(col_color[i].begin(), col_color[i].end());
        len = col_color[i].size();
        sum = 0,pre = 0;
        for (int j = 0;j < len;j++) {
            //dbg(col_color[i][j],i);
            sum += col_color[i][j];
        }
        for (int j = 0;j < len;j++) {
            sum -= col_color[i][j];
            ans += (sum - col_color[i][j] * (len - j - 1));
            ans += (col_color[i][j] * j - pre);
            pre += col_color[i][j];
        }
    }
    cout << ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}