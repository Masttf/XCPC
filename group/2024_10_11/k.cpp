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
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    //vector vis(n + 1, vector<int>(m + 1));
    auto checkT = [&](int x, int y) -> bool{
        for(int i = 0; i <= 2; i++){
            if(y + i > m)return false;
            if(a[x][y + i] != '#')return false;
        }
        for(int i = 1; i <= 4; i++){
            if(x + i > n)return false;
            if(a[x + i][y + 1] != '#')return false;
        }
        for(int i = 1; i <= 4; i++){
            if(a[x + i][y + 2] == '#')return false;
            if(a[x + i][y] == '#')return false;
        }
        return true;
    };
    auto colorT = [&](int x, int y) -> void{
        for(int i = 0; i <= 2; i++){
            // dbg(x, y + i);
            a[x][y + i] = '.';
        }
        for(int i = 1; i <= 4; i++){
            // dbg(x + i, y + 1);
            a[x + i][y + 1] = '.';
        }
    };
    auto checkA = [&](int x, int y) -> bool{
        for(int i = 0; i <= 4; i++){
            if(x + i > n)return false;
            if(a[x + i][y] != '#')return false;
        }
        // dbg("???", vis[6][6]);
        for(int i = 0; i <= 4; i++){
            if(y + 2 > m)return false;
            if(a[x + i][y + 2] != '#')return false;
        }
        // dbg("ytes");
        if(a[x][y + 1] != '#' || a[x + 2][y + 1] != '#')return false;
        // dbg("??")
        return true;
    };
    auto colorA = [&](int x, int y) -> void{
        for(int i = 0; i <= 4; i++){
            a[x + i][y] = '.';
        }
        for(int i = 0; i <= 4; i++){
            a[x + i][y + 2] = '.';
        }
        a[x][y + 1] = '.';
        a[x + 2][y + 1] = '.';
    };
    auto checkP = [&](int x, int y) -> bool{
        for(int i = 0; i <= 4; i++){
            if(x + i > n)return false;
            if(a[x + i][y] != '#')return false;
        }
        for(int i = 0; i <= 2; i++){
            if(y + 2 > m)return false;
            if(a[x + i][y + 2] != '#')return false;
        }
        if(a[x][y + 1] != '#' || a[x + 2][y + 1] != '#')return false;
        if(a[x + 3][y + 2] == '#')return false;
        return true;
    };
    auto colorP = [&](int x, int y) -> void{
        for(int i = 0; i <= 4; i++){
            a[x + i][y] = '.';
        }
        for(int i = 0; i <= 2; i++){
            a[x + i][y + 2] = '.';
        }
        a[x][y + 1] = '.';
        a[x + 2][y + 1] = '.';
    };
    int ans1 = 0, ans2 = 0, ans3 = 0;
    // dbg(checkA(7, 3));
    for(int i = n; i >= 5; i--){
        for(int j = m; j >= 1; j--){
            if(a[i][j] == '#'){
                if(j - 1 >= 1 && checkT(i - 4, j - 1)){
                    // dbg("T", i - 4, j - 1);
                    ans1++;
                    //dbg(i, j);
                    colorT(i - 4, j - 1);
                }
                if(checkP(i - 4, j)){
                    // dbg("P", i - 4, j);
                    ans3++;
                    colorP(i - 4, j);
                }
                if(j - 2 >= 1 && checkA(i - 4, j - 2)){
                    // dbg("A", i - 4, j - 2);
                    ans2++;
                    colorA(i - 4, j - 2);
                }
            }

        }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << '\n';
    // }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}